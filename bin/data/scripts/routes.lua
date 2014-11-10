
module("pf", package.seeall)

require 'Object'
local Object = pf.Object

Routes = Object:new{routes = {}}

function Routes:add(route)
    self.routes[route.address] = route
end

function Routes:delete(address)
    self.routes[address] = nil
end

function Routes:handle_message(msg)
    for k in pairs(self.routes) do
        if string.match(k, msg.address) then
            self.routes[k].action(unpack(msg))
        end
    end
end

