
function setup()
	print("Hello from Aviator embedded!")
	print("That's right, beetches!!")
end

function update()
end


function draw()
	for i=1,3 do
		color(math.random(), math.random(), math.random(), 1.0)
		line(7,0, math.random(120, 560), math.random(100, 800))
		solidCircle(math.random(0, 40), math.random(0,878), 16, 15)
	end
end

function handleMessage(message)
	print("handleMessage")
	print("address", message.address)
	print("args:")
	for k, v in ipairs(message) do
		print(k, v)
	end
end