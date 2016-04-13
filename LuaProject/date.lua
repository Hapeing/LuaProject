nrOfTimesCalled = 0

time = function()
	
	nrOfTimesCalled = nrOfTimesCalled + 1

	return os.date() .. " " .. nrOfTimesCalled
	
end