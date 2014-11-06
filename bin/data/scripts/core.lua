
package.path = package.path .. ';../../../data/scripts/?.lua'

require 'routing'
require 'slab'

local routing = pf.routing
local slab = pf.slab

function setup()
	print("welcome to pxlfkr")
	
	slab.add_layer("test")
	
	routing.route{address = "/inject",
		  action = function(code)
					 slab.inject("test", code)
				   end
	}
	
	routing.route{address = "/set",
		  action = function(key, value)
					 slab.set("test", key, value)
				   end
	}
	
	routing.route{address = "/clear",
		  action = function()
					 slab.clear("test")
				   end
	}
	
	routing.route{address = "/control",
		  action = function(controller, value)
					 slab.control("test", controller, value)
				   end
	}
	
	routing.route{address = "/load",
		  action = function(name)
					 slab.load("test", name)
				   end
	}

        of.background(0)
end

function update()
	slab.update()
end

function draw()
        of.setColor(255, 255, 255)
        for i = 1,10 do
            of.drawBitmapString("WELCOME TO PXLFKR", 20*i, 15*i)
        end
	slab.draw()
end

function osc(message)
	routing.handle_message(message)
end
