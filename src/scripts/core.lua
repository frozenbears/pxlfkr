
--TODO: do this corrctly
package.path = package.path .. ';PixelFucker.app/Contents/Resources/?.lua'

require 'routing'
require 'slab'

local routing = pf.routing
local slab = pf.slab

function setup()
	print("Welcome to PixelFucker")
	
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
					 slab.control(controller, value)
				   end
	}
	
end

function update()
	slab.update()
end

function draw()
	slab.draw()
end

function osc(message)
	routing.handle_message(message)
end