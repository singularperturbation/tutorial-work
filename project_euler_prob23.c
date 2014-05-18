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

// EDIT: (After finished)
// Looks like others solutions were to precompute sums for all abundant
// numbers where sum was <= 28123, then see if each number from 1 to 28123
// was in this list of sums by using a map.  This is probably order
// of magnitude better than my solution (takes ~1 minute on my computer).

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define PROB23DEBUG 0
#define MAXPOSSIBLE 28124

// Returns 1 if is an abundant number, zero if not 

int isAbundant(int input){
    int numDivisors = 1;
    int sumDivisors = 0;
    int curSize = 50, stepSize=50;
    // Will need to expand if have > 50 proper divisors
    int *divisors = (int * ) calloc(curSize*sizeof(int),sizeof(int) );
    int maxNum = input;
    int i = 0;

    // Always divisible by 1 (though don't count itself)
    divisors[0] = 1;

    for (i = 2; i < maxNum; i++){
      if ( 0 == (input % i) ) {
        if ( (numDivisors + 10) >= curSize){
          curSize += stepSize;
          divisors = (int * ) realloc(divisors,curSize*sizeof(int));
        }
        divisors[numDivisors] = i;
        numDivisors++;
      }
    }

    // Found all divisors, now need to sum
    for (i = 0; i < numDivisors; i++){
      sumDivisors += divisors[i];
    }

    free(divisors);

    if (sumDivisors > input)
      return 1;

    return 0;
}

int canBeSummed(int input, int *abundantNumbers, int length){
    int firstPos = 0, secondPos = 0;
    
    for (firstPos = 0; firstPos < length; firstPos++){
        for (secondPos=firstPos; secondPos < length; secondPos++){
            if (abundantNumbers[firstPos] + abundantNumbers[secondPos] == input){
               return 1;
        }
      }
    }

    return 0;
}

int main(int argc, char *argv[]){
    int *all = (int * ) calloc(sizeof(int)*MAXPOSSIBLE,sizeof(int));
    long int totSum = 0;
    int i=0,numFound=0;


    for (i = 2; i < MAXPOSSIBLE; i++){
        if (1 == isAbundant(i) ){
           all[numFound] = i;
           numFound++;
        }
     }
     
     #ifdef PROB23DEBUG
     printf("Found all abundant numbers < 28124\n");
     
     for (i = 0; i < (numFound); i++){
         printf("Abundant number %d: %d\n",i,all[i]);
     }
     #endif
     // After we've found all the abundant numbers, loop from 1 to 28124 and
     // sum those that can't be summed by two abundant.

     for (i = 1; i < MAXPOSSIBLE; i++){
         if (0 == canBeSummed(i,all,numFound) ){
          #ifdef PROB23DEBUG
          printf("Found %d!\n", i);
          #endif
          totSum += (long int) i; 
         }
     } 

     printf("DONE\n");
     printf("Sum of numbers < 28124 can't be summed from 2 abundant: %ld\n", totSum);
     free(all);
     return 0;
}
