
module ("pf.sandbox", package.seeall)

function make_environment()
	--TODO: do this correctly
	local env = {}
	for key, value in pairs(_G) do env[key] = value end
	env.update = nil
	env.draw = nil
	env.setup = nil
	env.osc = nil
	env.pf = nil
	return env
end

local function do_function(func, environment, args)
	setfenv(func, environment)
	if args then return pcall(func, unpack(args))
	else
		local status, message = pcall(func)
		if not status then print(message) end
	end
end

function execute(code, environment)
	local func, message = loadstring(code)
	if not func then return nil, message end
	do_function(func, environment)
end
