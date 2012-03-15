
module("pf.slab", package.seeall)

require 'sandbox'
local sandbox = pf.sandbox

local layers = {} -- of layers, indexed by numerical id or string

-- sandbox utils
-- TODO: move to own module?


local function create_layer()
	--  table with a function env, fbo, etc.
	return {environment = sandbox.make_environment()}
end

function add_layer(id)
	print ("add layer " .. id)
	layers[id] = create_layer()
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
	layers[id].environment = sandbox.make_environment()
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