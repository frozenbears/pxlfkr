
module("pf.slab", package.seeall)

local sandbox = require 'sandbox'

function new()
  local slab = {}
  slab.layers = {}
  return slab
end

function layer()
  local l = {}
  l.environment = sandbox.environment()
  return l
end

function add_layer(slab, id)
  slab.layers[id] = layer()
end

function delete_layer(slab, id)
  slab.layers[id] = nil
end

function inject(slab, id, code)
  if slab.layers[id] then
    local layer = slab.layers[id]
    sandbox.inject(layer.environment, code)
  end
end

function set(slab, id, key, value)
  if slab.layers[id] then
    local layer = slab.layers[id]
    sandbox.set(layer.environment, key, value)
  end
end

function load(slab, id, name)
  local name = name..".lua"
  local path = "/Users/"..os.getenv("USER").."/.pf/devices/"..name 
    
  io.input(path)
  local code = io.read("*all")
    
  clear(slab, id)
  inject(slab, id, code)
end

function reset(slab)
  slab.layers = {}
end

function update(slab)
  for id,layer in pairs(slab.layers) do
    sandbox.update(layer.environment)
  end
end

function draw(slab)
  for id,layer in pairs(slab.layers) do
    sandbox.draw(layer.environment)
  end
end

return pf.slab
