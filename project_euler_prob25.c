#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"

// How to efficiently calculate Fibonacci:
//
// Use non-recursive, because we're counting up instead of down
//
// Check length of digits on each?  Would involve converting back
// and forth between strings

int getLength(mpz_t input,char *fibString){
    mpz_get_str(fibString,10,input);
    int i = 0;
    for (i = 0; fibString[i] != '\0'; i++){
      ;
    }
    return i;

}

int main(int argc, char* argv[]){
    int numTerm = 2;
    mpz_t fib1, fib2,temp;
    mpz_inits(fib1,fib2,temp,NULL);
    char *fibString = (char *) calloc(2000*sizeof(char),sizeof(char));

    mpz_set_si(fib1, (long int) 1);
    mpz_set_si(fib2, (long int) 1);

    while(getLength(fib2,fibString) < 1000){
         numTerm++;
         mpz_set(temp,fib2);
         mpz_add(fib2,fib2,fib1);
         mpz_set(fib1,temp);
    }

    printf("Term number to have 1000-digit fibonacci string: %d\n",numTerm);



    free(fibString);
    mpz_clears(fib1,fib2,temp,NULL);
    return 0;

}
