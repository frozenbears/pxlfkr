
module("pf.routing", package.seeall)

local routes = {}

function route(route)
	local key = route.address
	routes[key] = route
end

function delete_route(address)
	local key = route.address
	routes[key] = nil
end

function handle_message(msg)
	for k in pairs(routes) do
		if string.match(k, msg.address) then
			routes[k].action(unpack(msg))
		end
	end
end


