/*
 * myfuncts.h
 *
 *  Created on: Aug 11, 2012
 *      Author: ssimmons
 *
 * Comments about defaults are for project Euler problem 12.
 *
 * WARNING: FACTORIZATION AS I HAVE WRITTEN IT IS INEFFICIENT AND HAS A BUG
 * BUILT IN!  IF LIST OF PRIMES IS TOO LOW TO FACTORIZE COMPLETELY, THEN THE
 * FUNCTION WILL FACTORIZE INCOMPLETELY, LEAVING WHATEVER IS LEFT.  THIS COULD
 * BE DETECTED BY RETURNING NULL OR WARNING, BUT IT IS SUFFICIENT FOR MY NEEDS
 * FOR THIS THIS PROBLEM.
 *
 */

#ifndef MYFUNCTS_H_
#define MYFUNCTS_H_

#define MIN_FACTOR_SIZE 10


typedef struct prime_and_power factor;

void *era_sieve(int input[], int length);  // input[] of length 8000 to get 1000 primes
void *factorize(int input, int *primes);   // Returns pointer to int array of factors

void clean(int *primes, factor *factors); // Cleaning up memory after done

struct  prime_and_power{
	int exponent;
	int value;
};

#endif /* MYFUNCTS_H_ */
