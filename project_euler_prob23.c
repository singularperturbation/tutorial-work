/* Project Euler Problem 23:
 * Created on: 4/27/2014 
 *
 * Description:
 * Perfect number:
 * Sum of proper divisors is exactly equal to number.
 *
 * Deficient number: sum of divisors less than number.
 *
 * Abundant: sum of divisors > number.
 *
 * Problem:
 * Find sum of all positive integers which cannot be written as sum of two
 * abundant numbers.  
 *
 * Math fact: all numbers > 28123 can be written as sum of two abundant
 * numbers.
 *
 */

// Ideas on how to solve:
// Find all abundant numbers less than 28123 
// Smells like a linear algebra problem?

// Something like (if 3 abundant numbers)
// A_0 * x + A_1 * Y + A_2 * Z = number
// No, this will have arbitrarily many
// (though not necessarilty integer) solutions for coefficients.

// Simplifies considerably: has to be sum of *two* abundant numbers
//
// What is # of abundant numbers < 28123?  Stupid obvious way is n^2 complexity
// ...hmmm.  If all numbers < 28123 were abundant, then would be ~9E8 ops... not
// unfeasible, but can we do better?
//
// Bah.  Whatever - will think of smarter way if needs to be faster... 
// actually, one thing we could do would be to memoize the combos of all the
// abundant numbers.  How expensive could this be?
//
// Assume int size = 4 bytes, ~ 1E9 total combinations, 4E9 bytes == ~3.8 GB... yeah, no.
// Get list of divisors for each number by looping from two to n/2, and check mod.
// Then sum the number of divisors?  Can have array of size 1 .. n?
// Just allocate at beginning for 1 .. 28123 and rewrite with zeros for 1 to n.
//
// Once we have a list of all abundant numbers, it will be n^2 problem for much
// smaller n.  This would be much better.


#include <stdio.h>
#include <stdlib.h>
#define MAXPOSSIBLE 28123

// Returns 1 if is an abundant number, zero if not 

int isAbundant(int input){
    int numDivisors = 0;
    int sumDivisors = 0;
    int curSize = 50;
    int *divisors = (int * ) calloc(50*sizeof(int),sizeof(int) );
    // Will need to expand if have > 50 proper divisors
   

    free(divisors);
    return 0;
}


int main(int argc, char *argv[]){
    int all[MAXPOSSIBLE];
    int i=0,numFound=0;
    for (i = 0; i< MAXPOSSIBLE; i++){
        all[i] = 0;
    }

    for (i = 0; i < MAXPOSSIBLE; i++){

        if (1 == isAbundant(i) ){
           numFound++;
           all[numFound] = i;
        }
     }
     
     // After we've found all the abundant numbers, loop from 1 to 28123 and
     // sum those that can't be summed by two abundant
           
    

     printf("DONE\n");
     return 0;
}
