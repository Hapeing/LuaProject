function fibb()
	Phi = (1 + math.sqrt(5))/2
	phi = (1 - math.sqrt(5))/2
	
	table = {}

	for i = 1, 20 do 
		table[i] = (math.pow(Phi, i) - math.pow(phi, i))/math.sqrt(5)
	end
	return table
end