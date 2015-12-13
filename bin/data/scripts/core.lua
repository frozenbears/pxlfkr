
package.path = package.path .. ';../../../data/scripts/?.lua'

local routing = require 'routing'
local slab = require 'slab'

local routes = {} 
local surface = slab.new()

local start_screen = true

function route_action(address, f)
  routing.add(routes, {address = address, action = f});
end

function setup()
  print("welcome to pxlfkr")
    
  of.setBackgroundColor(0)
  math.randomseed(os.time())
    
  route_action("/new", function(id)
    slab.add_layer(surface, id)
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
    slab.add_layer(surface, id)
  end)

  route_action("/load", function(id, name)
    slab.load(surface, id, name)
  end)

  route_action("/reset", function()
    slab.reset(surface)
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
        of.drawBitmapString("WELCOME TO PXLFKR", 20*i, 15*i)
    end
  else
    slab.draw(surface)
  end
end

function osc(message)
  routing.handle_message(routes, message)
end
