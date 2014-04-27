numsToCheck = {}
totalSum = 0
for i = 1,9999 do
  numsToCheck[i] = true
end

function divisors(input)
  output = {}
  i = 1
  numDivs = 1
  for i=1,(input-1) do
    if ( (input % i) == 0) then
      output[numDivs] = i
      numDivs = numDivs + 1
    end
  end

  return output
end

function sum(divs)
  i = 1
  local temp = 0
  for i =1,#divs do
    temp = temp+divs[i]
  end

  return temp

end

function isAmicable(input)
  divs = divisors(input)
  temp = sum(divs)
  if ( sum(divisors(temp)) == input) then
    return true,temp
  end
  return false,0
end

for i = 1,9999 do
  local num = 0
  local amicable = false
  if (numsToCheck[i] == false) then goto continue end
  amicable,num = isAmicable(i)
  if (num == i) then amicable=false end

  if amicable then
    numsToCheck[num] = false
    totalSum = totalSum + i + num
  end

  ::continue:: 
end

print(totalSum)
