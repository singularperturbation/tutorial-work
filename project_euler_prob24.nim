import algorithm
var digits: seq[int] = @[0,1,2,3,4,5,6,7,8,9]
var permutations: seq[string] = @[]
var numPermutations = 0

# Algorithm: using Heap's algorithm (from Wikipedia).
# Find millionth lexicographic permutation of [0..9]

proc compareStrings(a,b: string): int=
  if (a<b):
    return -1 
  if (a>b):
    return 1
  else:
    return 0

proc reduceSeq(numbers: seq[int]): string=
  var tempString = ""
  for i in numbers:
    tempString = tempString & $i
  return tempString

proc swap(x,y: int, input: var seq[int])=
  var temp:int = input[x-1]
  input[x-1] = input[y-1]
  input[y-1] = temp

proc generate(n : int, numbers: var seq[int])=
  assert(len(numbers) >= n)
  if n == 1:
    permutations.add(reduceSeq(numbers))
  else:
    for c in 1..n:
      generate(n-1,numbers)
      swap(if ( (n mod 2)== 1): 1 else: c, n, numbers)

generate(10,digits)
sort(permutations,compareStrings)
echo("One millionth permutation: " & $permutations[999999])
