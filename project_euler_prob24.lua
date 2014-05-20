--[[
  Project Euler Problem 24:
  Created by singularperturbation 5/19/2014

  Find 1 millionth lexicographic permutation of
  0,1,2,3,4,5,6,7,8,9

  Lexicographic permutation example: (0,1,2,3)
  0123
  0132
  0213
  0231
  0312
  0321
  1023
  1032
  1230
  1320
  ... goes on

  So how do we actually calculate?
  Need to have 10-elment array of "1" to "10" to specify how to
  put together number.

  Only have ~3.6 * 10^6 permutations (10!).  Just brute force
  this mofo (calculate all, sort table, get 1 millionth).

  Generating all permutations:
  Loop over elements of 'digits', and places of array for output.
  Need to think about how to do this.
-- ]]

local digits = {0,1,2,3,4,5,6,7,8,9}
local numPermutations = 0

local function fact(n)
  if n == 1 then return 1 end
  return n * fact(n-1)
end

for i = 1,fact(10) do
  print(fact(10))
end
