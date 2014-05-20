--[[
  Slightly different approach (created 5/19/2014)
  This solves the problem using a pre-built table of sums,
  which is about 30x speedup (using LuaJIT) over C version which recomputes
  sum for each number from 1 to 28123.

  Lua (no JIT) is still about 5x speedup.


  Caching, yo...

  Still not very efficient b/c uses trial divison.
  Lua's table syntax also was a bit wonky here.

--]]
local MAX = 28123
local abundantNums = {}
local abundantSums = {}
local val2 = 0
local sum = 0
local numFound = 1

local sumDivs = function(input)
  local i = 1
  local retVal = 0

  if (input == 1) then return 1 end
  
  for i = 1,(input/2) do
    if ( (input % i ) == 0 ) then
      retVal = retVal + i
    end
  end

  return retVal
end

for i = 1,MAX do
  if ( sumDivs(i) > i) then
    abundantNums[numFound] = i
    numFound = numFound + 1
  end
end

i,val1 = next(abundantNums)

while (i) do
  j = i
  val2 = val1
  while (j) do
    if (abundantNums[i] + abundantNums[j] > 28124) then 
      j,val2 = next(abundantNums,j)
      break 
    end
    abundantSums[val1 + val2] = true
    j,val2 = next(abundantNums,j)
  end
  i,val1 = next(abundantNums,i);
end

-- Now we need to loop over 1 to 28123 and see which are not found in
-- abundantSums

for i = 1,MAX do
  if (abundantSums[i] ~= true) then
    --print("Found " .. i)
    sum = sum + i
  end
end
print(sum)
