-- Summary: take in number (integer) as input
-- and return array with elements as binary
function convNumRouteArray(input)
  assert(type(input) == "number")
  output = {}
  digit = 14

  i = 0
  -- Initialize array
  for i=1,14 do
    output[i] = 0
  end

  if (input > 16383) then
    return nil
  end

  while(input > 0) do
    input = input / 2
    if ( (input % 1) ~= 0 ) then
      output[digit] = 1
    else
      output[digit] = 0
    end
    input = input - ( input % 1)
    digit = digit - 1
  end
 
  return output
end

function parseline(input)
  output, temp = {},{}
  wordcount = 1
  for temp in input:gmatch("%w+") do
    output[wordcount] = tonumber(temp,10)
    wordcount = wordcount + 1;
  end
  return output;
end
