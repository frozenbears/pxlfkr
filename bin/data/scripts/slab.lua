module("pf.slab", package.seeall)

local sandbox = require 'sandbox'
local list = require 'list'

local param_type_map = {uniform1f = "setUniform1f",
                        uniform2f = "setUniform2f",
                        uniform3f = "setUniform3f",
                        uniform4f = "setUniform4f",
                        uniform1i = "setUniform1i",
                        uniform2i = "setUniform2i",
                        uniform3i = "setUniform3i",
                        uniform4i = "setUniform4i"}

local resource_paths = {"/Users/"..os.getenv("USER").."/.pf/devices/", "../../../data/devices/"}

function append_child(a, b)
  local node = list.append(a.children, b)
  node.parent = a
  return node
end

function prepend_child(a, b)
  local node = list.prepend(a.children, b)
  node.parent = a
  return node
end

function insert_after(a, b)
  local node = list.insert_after(a.parent.children, a, b)
  node.parent = a.parent
  return node
end

function insert_before(a, b)
  local node = list.insert_before(a.parent.children, a, b)
  node.parent = a.parent
  return node
end

function replace(a, b)
  local node = list.replace(a.parent.children, a, b)
  node.parent = a.parent
  a.parent = nil
  return node
end

function delete_child(a, b)
  list.delete_node(a.children, b)
  a.parent = nil
end

-- recursively yield the group and its children
function traverse(g)
  coroutine.yield(g)
  if g.children then
    for child in list.values(g.children) do
      traverse(child)
    end
  end
end

function group_iter(g)
  return coroutine.wrap(function() traverse(g) end)
end

local function dir_exists(path)
  local attr = lfs.attributes(path)
  if attr and attr.mode == "directory" then return true end
  return false
end

local function file_exists(path)
  local attr = lfs.attributes(path)
  if attr and attr.mode == "file" then return true end
  return false
end

local function dirtree(dir)
  assert(dir and dir ~= "", "directory parameter is missing or empty")
  if string.sub(dir, -1) == "/" then
    dir=string.sub(dir, 1, -2)
  end

  local function yieldtree(dir)
    coroutine.yield(dir)
    for entry in lfs.dir(dir) do
      if entry ~= "." and entry ~= ".." then
        entry=dir.."/"..entry
        local attr=lfs.attributes(entry)
        if attr.mode == "directory" then
          coroutine.yield(entry,attr)
          yieldtree(entry)
        end
      end
    end
  end

  return coroutine.wrap(function() yieldtree(dir) end)
end

local function path_for_resource(name)
  for i, path in pairs(resource_paths) do
    if dir_exists(path) then
      for dir in dirtree(path) do
        local full_path = dir .. "/" .. name
        if file_exists(full_path) then return full_path end
      end
    end
  end
end

local function path_for_resource_name(name, ext)
  local full_name = name .. "." .. ext
  return path_for_resource(full_name)
end

local function capture_fbo(slab)
  -- todo: bind this constant
  GL_RGBA = 0x1908
  local f = of.Fbo()
  f:allocate(slab.resolution.width, slab.resolution.height, GL_RGBA, 0)
  return f
end

local function allocate_fbos(slab, layer)
  layer.draw_fbo = capture_fbo(slab)
  layer.composite_fbo = capture_fbo(slab)
end

function set_resolution(slab, width, height)
  slab.resolution.width = width
  slab.resolution.height = height

  -- reallocate fbos
  for layer in group_iter(slab.graph) do
    allocate_fbos(slab, layer)
  end
end

function new(resolution)
  local slab = {}
  slab.resolution = resolution
  reset(slab)
  return slab
end

local function shader_program(slab, vert_path, frag_path, params)

  local shader = of.Shader()
  shader:load(vert_path, frag_path)

  local transform = function(a, b)
    shader:beginShader()
    of.clear(0)
    of.setColor(255)
    for name, param in pairs(params) do
      local type = param.type -- such as uniform1f
      local fname = param_type_map[type]
      assert(fname, "invalid type: " .. type)
      shader[fname](shader, name, param.value)
    end

    if a then
      shader:setUniformTexture("tex0", a:getTextureReference(), 0)
    end

    if b then
      shader:setUniformTexture("tex1", b:getTextureReference(), 1)
    end
    shader:setUniform1f("iGlobalTime", of.getElapsedTimef())

    shader:setUniform3f("iResolution", slab.resolution.width, slab.resolution.height, 0)

    of.rect(0, 0, slab.resolution.width, slab.resolution.height)
    shader:endShader()
  end
  return transform
end

local function environment(slab)

  local env = sandbox.environment()

  env.params = {}

  env.resolution = slab.resolution

  local bind_program = function(fname, e)
    return function(f, params)
      e[fname] = f
      for k, v in pairs(params) do
        e.params[k] = v
      end
    end
  end

  --[[
    todo:
    part of the problem with this is that a badly written draw program can erase params accidentally
    moving the default compositor construction to after load would reduce that risk
    in general I'm not sure if this params thing is fully baked. haven't even tried using it with a non-shader thing.
    how do you keep e.g. regular old params distinct from shader params. or compositing params.
  --]]

  local _shader_program = function()
    return function(vert, frag)
      local vert_path = path_for_resource(vert)
      local frag_path = path_for_resource(frag)
      assert(vert_path and frag_path, "unable to find " .. vert .. " or " .. frag)
      return shader_program(slab, vert_path, frag_path, env.params)
    end
  end

  env.shader_program = _shader_program()
  env.bind_program = bind_program("draw", env)
  env.bind_compositor = bind_program("composite", env)

  -- set up and bind the default compositor
  local blend_params = {opacity = {type = "uniform1f", value = 1.0}, blendmode = {type = "uniform1i", value = 0}}
  local blend_vert = "devices/compositors/shaders/blend.vert"
  local blend_frag = "devices/compositors/shaders/blend.frag"
  local compositor = shader_program(slab, blend_vert, blend_frag, blend_params)
  bind_program("composite", env)(compositor, blend_params)

  return env
end

local function layer(slab)
  local l = {}
  l.environment = environment(slab)
  allocate_fbos(slab, l)
  return l
end

function group(slab)
  local l = layer(slab)
  l.children = {}
  return l
end

function new_node(slab, element, id, add_action, target_id)
  assert(not slab.nodes[id], "duplicate node id: " .. id)

  -- todo: add_action constants

  local group
  if target_id then
    local target_element = slab.nodes[target_id]
    assert(target_element, "node not found: " .. target_id)
    local layer = target_element.value
    if layer.children then
      group = target_element.value
    else
      -- if appending or prepending, select the parent if the target isn't a group
      if add_action == 0 or add_action == 1 then
        group = target_element.parent.value
      else
        group = layer
      end
    end
  else
    group = slab.graph
  end

  -- make head the default
  add_action = add_action or 1

  local node

  if add_action == 0 then
    -- head
    node = prepend_child(group, element)
  elseif add_action == 1 then
    -- tail
    node = append_child(group, element)
  elseif add_action == 2 then
    -- before
    local target_node = slab.nodes[target_id]
    node = insert_before(target_node, element)
  elseif add_action == 3 then
    -- after
    local target_node = slab.nodes[target_id]
    node = insert_after(target_node, element)
  elseif add_action == 4 then
    -- replace
    local target_node = slab.nodes[target_id]
    node = replace(target_node, element)
    slab.nodes[target_id] = nil
  end

  slab.nodes[id] = node
end

function new_group(slab, id, add_action, target_id)
  local group = group(slab)
  new_node(slab, group, id, add_action, target_id)
end

local function flat_pairs(t)
  assert(#t %2 == 0, "flat pairs must be an even number")
  return coroutine.wrap(function()
    for i = 1, #t+1, 2 do
      coroutine.yield(t[i], t[i+1])
    end
  end)
end

function new_layer(slab, name, id, add_action, target_id, ...)
  local param_pairs = {...}
  if #param_pairs then
    -- count of param_pairs must be even
    assert(#param_pairs %2 == 0)
  end
  local layer = layer(slab)
  new_node(slab, layer, id, add_action, target_id)

  -- todo: make this less indirect
  load(slab, id, name)

  local param_pairs = {...}
  if #param_pairs then
    -- count of param_pairs must be even
    assert(#param_pairs %2 == 0)
  end
  -- set all provided params
  for k,v in flat_pairs(param_pairs) do
    param(slab, id, k, v)
  end
end

function delete_layer(slab, id)
  local node = slab.nodes[id]
  if node.parent then
    delete_child(node.parent, node)
  end
  slab.nodes[id] = nil
end

function inject(slab, id, code)
  if slab.nodes[id] then
    local layer = slab.nodes[id].value
    sandbox.inject(layer.environment, code)
    sandbox.setup(layer.environment)
  end
end

function set(slab, id, key, value)
  if slab.nodes[id] then
    local layer = slab.nodes[id].value
    local whitelist = {opacity=true, blendmode=true}
    if whitelist[key] then layer[key] = value end
  end
end

function clear(slab, id)
  if slab.nodes[id] then
    local layer = slab.nodes[id].value
    layer.environment = environment(slab)
  end
end

function load(slab, id, name)
  local path = path_for_resource_name(name, "lua")
  if path then
    io.input(path)
    local code = io.read("*all")
    clear(slab, id)
    inject(slab, id, code)
  end
end

local function set_param_rec(node, name, value)
  for element in group_iter(node.value) do
    local params = element.environment.params
    if params then
      params[name].value = value
    end
  end
end

local function set_param(node, name, value)
  local element = node.value
  local params = element.environment.params
  if params then
    params[name].value = value
  end
end

function param(slab, id, name, value, set_action)
  if slab.nodes[id] then

    set_action = set_action or 0
    local node = slab.nodes[id]

    if set_action == 0 then
      set_param(node, name, value)
    elseif set_action == 1 then
      set_param_rec(node, name, value)
    else
      error("invalid set action: " .. set_action)
    end

    set_param(node, name, value)
  end
end

function reset(slab)
  slab.nodes = {}
  -- todo: does this imply something weird about execution order if
  -- treating the graph as a sibling? how should that be handled?
  slab.root = {}
  slab.graph = group(slab)
  slab.nodes[0] = list.append(slab.root, slab.graph)
end

function update(slab)
  for layer in group_iter(slab.graph) do
    sandbox.update(layer.environment)
  end
end

function draw_layer(slab, layer, prev)
  local fbo = layer.draw_fbo
  local chain

  if layer.children then
    for child in list.values(layer.children) do
      chain = draw_layer(slab, child, chain)
    end
  end

  fbo:beginFbo()
  of.clear(0)
  of.pushStyle()
  if chain then
    chain:draw(0,0, slab.resolution.width, slab.resolution.height)
  else
    sandbox.draw(layer.environment, prev)
  end
  of.popStyle()
  fbo:endFbo()

  local composite_fbo = layer.composite_fbo
  if prev then
    composite_fbo:beginFbo()
    sandbox.composite(layer.environment, prev, fbo)
    composite_fbo:endFbo()
    return composite_fbo
  else
    -- todo: should this be "composited"? right now the primary layer of any group is unblended.
    -- returning composite_fbo breaks opacity for groups.
    -- this may indicate that the blend shader or some aspect of its implementation needs work
    return fbo
  end
end

function draw(slab)
  local composite = draw_layer(slab, slab.graph)
  local w = slab.resolution.width
  local h = slab.resolution.height

  local width_factor = of.getWidth() / w
  local height_factor = of.getHeight() / h
  local scale_factor = math.min(width_factor, height_factor)

  local scaled_width = w * scale_factor
  local scaled_height = h * scale_factor

  local origin_x = (of.getWidth() - scaled_width)/2
  local origin_y = (of.getHeight() - scaled_height)/2

  composite:draw(origin_x, origin_y, scaled_width, scaled_height)
end

return pf.slab
