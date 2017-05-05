module("pf.routing", package.seeall)

function add(routes, route)
  routes[route.address] = route
end

function delete(routes, address)
  routes[address] = nil
end

function handle_message(routes, msg)
  for k in pairs(routes) do
    if string.match(k,  msg.address) then
      routes[k].action(unpack(msg))
    end
  end
end

return pf.routing
