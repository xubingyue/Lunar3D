function lunar.load()
	local bob = lunar.utils.stringSplit("hi_ho_he", "_")
	local beb = lunar.utils.stringSplit("he_hi_ho", "_")
	print(beb[1])
end

function lunar.update(dt)
	
end

function lunar.draw()
	lunar.graphics.setColor(255, 0, 0)
	lunar.graphics.setBackgroundColor(100, 100, 100)
	
	lunar.graphics.drawCube(0, 0, 0, 1)
end