local ms = 5 --movement units per second

local x = 0.0
local y = 0.0
local z = 0.0
local rx = 0.0
local ry = 0.0
local rz = 0.0

crx = 0.0
crz = 0.0

function lunar.update(dt)
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
		crz = crz + dt
	end
	
	lunar.graphics.setCameraPosition(x, y, z)
	lunar.graphics.setCameraAngle(rx, ry, rz)
end

function lunar.draw()
	lunar.graphics.setColor(255, 0, 0)
	lunar.graphics.drawCube(0, 0, 0, 1)

	lunar.graphics.setColor(0, 255, 0)
	lunar.graphics.drawCube(0, 4, 0, 1.7)
	
	lunar.graphics.push()
	lunar.graphics.rotate(crz, crz, 0)
	lunar.graphics.setColor(0, 0, 255)
	lunar.graphics.drawCube(-3, 0, 0.2, 0.8)
	lunar.graphics.pop()
	
	lunar.graphics.rotate(0, 0, 0)
	
	lunar.graphics.setColor(255, 255, 0)
	lunar.graphics.drawCube(4, -1, -0.5, 1.1)
end