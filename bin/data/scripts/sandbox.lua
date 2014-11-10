
module ("pf", package.seeall)

require 'object'
local Object = pf.Object

local function make_environment()
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

local function dofunc(func, environment, args)
    setfenv(func, environment)
    if args then return pcall(func, unpack(args))
    else
        local status, message = pcall(func)
        if not status then print(message) end
        return status, message
    end
end

Sandbox = Object:new{environment=make_environment()}

function Sandbox:inject(code)
    local func, message = loadstring(code)
    
    if not func then 
        print(message)
        return nil, message 
    end
    
    return dofunc(func, self.environment)
end

function Sandbox:set(k, v)
  self.environment[k] = v
end

function Sandbox:setup()
    if self.environment.draw then
        self.environment.draw()
    end
end

function Sandbox:update()
    if self.environment.update then
        self.environment.update()
    end    
end

function Sandbox:draw()
    if self.environment.draw then
        self.environment.draw()
    end
end

