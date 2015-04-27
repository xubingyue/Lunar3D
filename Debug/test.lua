local movementspeed = 5 --units per second

local cx = 0.0
local cy = 0.0
local cz = 0.0
local crx = 0.0
local cry = 0.0
local crz = 0.0

function lunar.update(dt)
	if lunar.keyboard.isDown("w") then
		cz = cz + math.cos(cry / 180 * math.pi) * dt * movementspeed
		cx = cx - math.sin(cry / 180 * math.pi) * dt * movementspeed
	end
	if lunar.keyboard.isDown("s") then
		cz = cz - math.cos(cry / 180 * math.pi) * dt * movementspeed
		cx = cx + math.sin(cry / 180 * math.pi) * dt * movementspeed
	end
	if lunar.keyboard.isDown("a") then
		cz = cz - -math.sin(cry / 180 * math.pi) * dt * movementspeed
		cx = cx + math.cos(cry / 180 * math.pi) * dt * movementspeed
	end
	if lunar.keyboard.isDown("d") then
		cz = cz + -math.sin(cry / 180 * math.pi) * dt * movementspeed
		cx = cx - math.cos(cry / 180 * math.pi) * dt * movementspeed
	end
	if lunar.keyboard.isDown("lshift") then
		cy = cy - dt * movementspeed
	end
	if lunar.keyboard.isDown("lcontrol") then
		cy = cy + dt * movementspeed
	end
	if lunar.keyboard.isDown("up") then
		crx = crx - dt * 100
	end
	if lunar.keyboard.isDown("down") then
		crx = crx + dt * 100
	end
	if lunar.keyboard.isDown("left") then
		cry = cry - dt * 100
	end
	if lunar.keyboard.isDown("right") then
		cry = cry + dt * 100
	end
	
	lunar.graphics.setCameraPosition(cx, cy, cz)
	lunar.graphics.setCameraAngle(crx, cry, crz)
end

function lunar.draw()
	lunar.graphics.setColor(255, 0, 0)
	lunar.graphics.drawCube(0, 0, 0, 1)
end