package.path = package.path .. ';../../../data/scripts/?.lua'

local routing = require 'routing'
local slab = require 'slab'

local routes = {}
local surface = slab.new({width = 1024, height = 768})

local start_screen = true

function route_action(address, f)
  routing.add(routes, {address = address, action = f});
end

function setup()
  print("welcome to pxlfkr")

  of.setBackgroundColor(0)
  math.randomseed(os.time())

  -- todo: varargs

  route_action("/resolution", function(width, height)
    of.setWindowShape(width, height)
    slab.set_resolution(surface, width, height)
  end)

  route_action("/new_group", function(id, add_action, target_id)
    slab.new_group(surface, id, add_action, target_id)
    start_screen = false
  end)

  route_action("/new_layer", function(name, id, add_action, target_id, ...)
    slab.new_layer(surface, name, id, add_action, target_id, ...)
    start_screen = false
  end)

  route_action("/delete", function(id)
    slab.delete_layer(surface, id)
  end)

  route_action("/inject", function(id, code)
    slab.inject(surface, id, code)
  end)

  route_action("/set", function(id, key, value)
    slab.set(surface, id, key, value)
  end)

  route_action("/clear", function(id)
    -- is there a good reason for this?
    slab.clear(surface, id)
  end)

  route_action("/load", function(id, name)
    slab.load(surface, id, name)
  end)

  route_action("/reset", function()
    slab.reset(surface)
  end)

  route_action("/attach", function(id, name)
    slab.attach(surface, id, name)
  end)

  route_action("/param", function(id, name, value, set_action)
    slab.param(surface, id, name, value, set_action)
  end)
end

function update()
  slab.update(surface)
end

function draw()
  -- move this routine to slab?
  if start_screen then
    of.setColor(255, 255, 255)
    for i = 1,10 do
        of.drawBitmapString("OHAI!!!!!", 20*i, 15*i)
    end
  else
    slab.draw(surface)
  end
end

function osc(message)
  routing.handle_message(routes, message)
end
