local ms = 5 --movement units per second

local x = 0.0
local y = 0.0
local z = 0.0
local rx = 0.0
local ry = 0.0
local rz = 0.0

crx = 0.0
cry = 0.0
crz = 0.0

a = lunar.drawable.new()
a:set(2)
print(a:get())

function lunar.load()
	local bob = lunar.utils.stringSplit("hi_ho_he", "_")
	local beb = lunar.utils.stringSplit("he_hi_ho", "_")
	
	local bobstr = ""
	local bebstr = ""
	
	for i, v in ipairs(bob) do
		bobstr = bobstr .. v .. " "
	end
	
	for i, v in ipairs(beb) do
		bebstr = bebstr .. v .. " "
	end
	
	print("Bob split = " .. bobstr)
	print("Beb split = " .. bebstr)
end

function lunar.update(dt)
	dt = 0.001
	if lunar.keyboard.isDown("w") then
        z = z + math.cos(ry / 180 * math.pi) * dt * ms
        x = x - math.sin(ry / 180 * math.pi) * dt * ms
    end
    if lunar.keyboard.isDown("s") then
        z = z - math.cos(ry / 180 * math.pi) * dt * ms
        x = x + math.sin(ry / 180 * math.pi) * dt * ms
    end
    if lunar.keyboard.isDown("a") then
        z = z - -math.sin(ry / 180 * math.pi) * dt * ms
        x = x + math.cos(ry / 180 * math.pi) * dt * ms
    end
    if lunar.keyboard.isDown("d") then
        z = z + -math.sin(ry / 180 * math.pi) * dt * ms
        x = x - math.cos(ry / 180 * math.pi) * dt * ms
    end
    if lunar.keyboard.isDown("lshift") then
        y = y - dt * ms
    end
    if lunar.keyboard.isDown("lcontrol") then
        y = y + dt * ms
    end
    if lunar.keyboard.isDown("up") then
        rx = rx - dt * 100
    end
    if lunar.keyboard.isDown("down") then
        rx = rx + dt * 100
    end
    if lunar.keyboard.isDown("left") then
        ry = ry - dt * 100
    end
    if lunar.keyboard.isDown("right") then
        ry = ry + dt * 100
    end
	
	if lunar.keyboard.isDown("p") then
		crx = crx + dt * 40
		crz = crz + dt * 30
	end
	
	lunar.graphics.setCameraPosition(x, y, z)
	lunar.graphics.setCameraAngle(rx, ry, rz)
end

function lunar.draw()
	lunar.graphics.setColor(255, 0, 0)
	lunar.graphics.drawCube(0, 0, 0, 1)

	lunar.graphics.setColor(0, 255, 0)
	lunar.graphics.drawCube(0, 4, 0, 1.7)
	
	lunar.graphics.rotate(crx, cry, crz)
	lunar.graphics.setColor(0, 0, 255)
	lunar.graphics.drawCube(-3, 0, 0.2, 0.8)
	lunar.graphics.rotate(0, 0, 0)
	
	lunar.graphics.setColor(255, 255, 0)
	lunar.graphics.drawCube(4, -1, -0.5, 1.1)
end