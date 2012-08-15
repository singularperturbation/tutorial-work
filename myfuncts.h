/*
 * myfuncts.h
 *
 *  Created on: Aug 11, 2012
 *      Author: ssimmons
 *
 * Comments about defaults are for project Euler problem 12.
 */

#ifndef MYFUNCTS_H_
#define MYFUNCTS_H_

#define MIN_FACTOR_SIZE 10


typedef struct prime_and_power factor;

void *era_sieve(int input[], int length);  // input[] of length 8000 to get 1000 primes
void *factorize(int input, int *primes);
// Returns pointer to int array of factors
//  (primes here should be of length ~1000, as 1000th prime == 7919)

static void initialize_factor_list(int current_length, factor *factors);  // Used internally

void clean(int *primes, factor *factors); // Cleaning up memory after done

struct  prime_and_power{
	int exponent;
	int value;
};

#endif /* MYFUNCTS_H_ */
