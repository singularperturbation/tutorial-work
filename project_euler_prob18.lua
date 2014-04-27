-- Problem 18
-- Find maximum sum finding route through tree below.
--
--  A route is an n-tuple where n is the depth of the
--  tree-1
--
--  Here, n = 14 (15 is the depth - 1 )
--
--  Enumerating routes:
--  0 or 1 for left or right step, respectively
--
--  Ideas on how to get all possible routes:
--  1)
--  Insert one '1' into any position in the 14-tuple,
--  then insert another '1' into any position but the
--  one already occupied.  Continue until we've filled up
--  the array with ones.
--
--  This will work but is in factorial time (14!) vs. 2^14
--  (87 billion vs 16 thousand).  Not that lazy.
--
--  2) 
--  Count from 0 to 16384 in binary
--  Much better, but what does that mean?
--  00000000000000
--  00000000000001
--  00000000000010
--  00000000000011
--  etc.
--
--  Have position of 'leftmost' 1 and then do that way?
--  I don't really want to write my own decimal-binary
--  conversion routine just for this- way to cheat? (I.e., part of
--  stdlib?)
--
--  No, tonumber("string",base) only works base -> decimal
--  ...sigh.
--
--  Since don't want to implement *addition* as well as string
--  representaiton of binary, will just have an int-> 14-array
--  conversion function for this.

require('project_euler_prob18_helper')

max = 0

triangle_lines = [[
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
]]

lines = {}
count = 1;

for line in triangle_lines:gmatch("[^\r\n]+") do
  lines[count] = parseline(line)
  count = count + 1
end

count = 1

function sumRoute(route)
  -- route should be an array of length 14 with zeroes and one
  -- Step through lines[i = 1 to 15], and add to sum lines[pos]
  -- pos should start at 1 and add route
  local sum,pos,line = 0,1,0 
  for line = 1,15 do
    sum = sum + lines[line][pos]
    if line == 15 then break
    else
      pos = pos + route[line]
    end
  end
  return sum
end

for i = 0,16383,1 do
  local tempSum = 0
  local route = convNumRouteArray(i)
  tempSum=sumRoute(route)
  if (tempSum > max) then
    max = tempSum
  end
end

print("Value of maximum route: " .. max)
