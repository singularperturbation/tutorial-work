# Problem 25
# Already solved, but want to try rewriting using Nimrod's C interop

# proc whatever(params: ctypes): ctype {.header "gmp.h".}
# type import (example from manual):
#
# type
#   PFile {.importc: "FILE*", header: "<stdio.h>".} = distinct pointer
#   # import C's FILE* type; Nimrod will treat it as a new pointer type
#
# Could also import something as an object

# Make sure to link against libgmp:
{.passL: "-lgmp".}

type
  TMPZ_t {.importc: "mpz_t", header: "gmp.h".} = object

proc mpz_init(input: TMPZ_t ) {.importc, header: "gmp.h".}
proc mpz_clear(input: TMPZ_T) {.importc, header: "gmp.h".}

#proc mpz_initstring(n: varargs[TMPZ_t])= # Wrapper
#  for i in items(n):
#    mpz_init(i)

# Variable number of arguments with varargs will not work with C
# since C uses stdarg.h and va_list, whatever, whatever, and Nimrod uses array

proc mpz_get_str(buffer: cstring,base: cint, input: TMPZ_t) {.importc, header: "gmp.h".}
proc mpz_set_si(input: TMPZ_t, value: cint) {.importc, header: "gmp.h".}
proc mpz_set(toset: TMPZ_t, value: TMPZ_t) {.importc, header: "gmp.h".}
proc mpz_add(output, param1, param2: TMPZ_t) {.importc, header: "gmp.h".}

proc getLength(input: TMPZ_t,buffer: cstring): int=
  mpz_get_str(buffer,10,input)
  return len(buffer) # Works because Nimrod strings are null terminated

proc main() =
  var
    fib1,fib2,temp: TMPZ_t
    numTerm = 2
    fibString: cstring = newString(2000)
  
  #mpz_initstring(fib1,fib2,temp)
  mpz_init(fib1)
  mpz_init(fib2)
  mpz_init(temp)
  mpz_set_si(fib1, 1)
  mpz_set_si(fib2, 1)

  while (getLength(fib2,fibString) < 1000):
    inc(numTerm)
    mpz_set(temp,fib2)
    mpz_add(fib2,fib2,fib1)
    mpz_set(fib1,temp)

  echo("Term number to have 1000-digit fibonacci string: " & $numTerm)
  mpz_clear(fib1)
  mpz_clear(fib2)
  mpz_clear(temp)

main()
