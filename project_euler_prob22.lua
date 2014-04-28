--[[ Problem 22
--   
--   Summary: Want to get sum of 'name scores'
--   Get names from file, put into alphabetical order, and
--   then calculate 'name score' as sum of alpha value of 
--   letters multiplied by position in list
--]]
--
-- String iterator? Use string.gmatch
-- Could also just set io.input, do io.lines()

local AtoZ = {}

local sum = 0 

for i = 1,26 do AtoZ[string.char(64+i)] = i end

local function sumString(input)
  local sum = 0
  local i = 1
  for i=1,input:len() do
    sum = sum + AtoZ[input:sub(i,i)]
  end
  return sum
end

local nameTable = {}
local infile = assert(io.open("problem22_names.txt","r"))
local names = infile:read("*a")
infile:close()

for line in names:gmatch("%w+") do 
  nameTable[#nameTable+1] = line
end

-- Too lazy to write my own sort myfunction
table.sort(nameTable)

for i = 1,#nameTable do
  sum = (sumString(nameTable[i]) * i) + sum
end

print(sum)
