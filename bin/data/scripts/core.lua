
package.path = package.path .. ';../../../data/scripts/?.lua'

require 'routes'
require 'slab'

local routes = pf.Routes:new()
local slab = pf.Slab:new()

function setup()
    print("welcome to pxlfkr")
    
    of.setBackgroundColor(0)
    math.randomseed(os.time())
    
    slab:add_layer("test")
    
    routes:add{address = "/inject",
                action = function(code)
                             slab:inject("test", code)
                         end
    }
    
    routes:add{address = "/set",
                action = function(key, value)
                             slab:set("test", key, value)
                         end
    }
    
    routes:add{address = "/clear",
                action = function()
                             slab:clear("test")
                         end
    }
    
    routes:add{address = "/control",
                   action = function(controller, value)
                       slab:control("test", controller, value)
                   end
    }
    
    routes:add{address = "/load",
                 action = function(name)
                              slab:load("test", name)
                          end
    }
end

function update()
    slab:update()
end

function draw()
    of.setColor(255, 255, 255)
    for i = 1,10 do
        of.drawBitmapString("WELCOME TO PXLFKR", 20*i, 15*i)
    end
    slab:draw()
end

function osc(message)
    routes:handle_message(message)
end
