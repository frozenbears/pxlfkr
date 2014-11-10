
module("pf", package.seeall)

require 'sandbox'
require 'object'

local Object = pf.Object;
local Sandbox = pf.Sandbox

Layer = Object:new()

function Layer:inject(code)
    self.sandbox:inject(code)
end

function Layer:set(k, v)
    self.sandbox:set(k, v)
end

function Layer:setup()
    self.sandbox:setup()
end

function Layer:update()
    self.sandbox:update()
end

function Layer:draw()
    self.sandbox:draw()
end

-------------------------------------------

Slab = Object:new{layers={}, controllers={}}

function Slab:create_layer(id)
    self.controllers[id] = {}
    
    local sandbox = Sandbox:new{bind_controller = function(controller, fn)
                                                      self.controllers[id][controller]=fn
                                                  end
    }
    return Layer:new{sandbox = sandbox}
end

function Slab:add_layer(id)
    self.layers[id] = self:create_layer(id)
end

function Slab:inject(id, code)
    if self.layers[id] then
        self.layers[id]:inject(code)
    end
end

function Slab:set(id, key, value)
    if self.layers[id] then
        self.layers[id]:set(key, value)
    end
end

function Slab:clear(id)
    --this is the same as add_layer for the moment, but not for long
    self.layers[id] = self:create_layer(id)
end

function Slab:control(id, controller, value)
    for _id, binding in pairs(self.controllers) do
        if binding[controller] then
            self.controllers[id][controller](value)
        end
    end
end

function Slab:load(id, name)
    local name = name..".lua"
    local path = "/Users/"..os.getenv("USER").."/.pf/devices/"..name 
    
    io.input(path)
    local code = io.read("*all")
    
    self:clear(id)
    self:inject(id, code)
end

function Slab:update()
    for id,layer in pairs(self.layers) do
        layer:update()
    end
end
        
function Slab:draw()
    for id,layer in pairs(self.layers) do
        layer:draw()
    end
end
