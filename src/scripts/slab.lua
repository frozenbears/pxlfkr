
module("pf.slab", package.seeall)

require 'sandbox'
local sandbox = pf.sandbox

local layers = {} -- of layers, indexed by numerical id or string
local controllers = {}

-- sandbox utils
-- TODO: move to own module?


local function create_layer(id)
	--  table with a function env, fbo, etc.
	
	local env = sandbox.make_environment()
	
	controllers[id] = {}
	env.bind_controller = function(controller, fn)
						      controllers[id][controller]=fn
						  end

	return {environment = env}
end

function add_layer(id)
	print ("add layer " .. id)
	layers[id] = create_layer(id)
end

function inject(id, code)
	if layers[id] then
		sandbox.execute(code, layers[id].environment)
	end
end

function set(id, key, value)
	if layers[id] then
		layers[id].environment[key] = value
	end
end

function clear(id)
	--this is the same as add_layer for the moment, but not for long
	layers[id] = create_layer(id)
end

function bind_controller(controller, fn)
    controllers[controller] = fn
end

function control(controller, value)
	for id, binding in pairs(controllers) do
		if binding[controller] then
			controllers[id][controller](value)
		end
	end
		
end

function update()
	for id,layer in pairs(layers) do
		if layer.update then
			layer.environment.update()
		end
	end
end
		
function draw()
	for id,layer in pairs(layers) do
		if layer.environment.draw then
			layer.environment.draw()
		end
	end
end