/*
 * project_euler_prob12.c
 *
 *  Created on: Aug 11, 2012
 *      Author: ssimmons
 *
 *  Project Euler: Problem 12
 *  Find smallest triangular number with >500 divisors.
 *
 *	Strategy: Use Sieve of Eratosthenes, trial division to factor n, n+1
 *	for the nth triangular number.  Then, add exponents (subtracting one from 2).
 *
 *	Find # of divisors by multiplying exponent of each prime +1 by others+1.
 *	If # divisors >500: Found your solution.  If not, increment n and try again.
 *
 *	NOTE: HINDSIGHT TELLS THAT FACTORING N & N+1 WOULD BE MUCH MORE EFFICIENT.  ONCE
 *	AGAIN, LAZINESS PREVENTS FURTHER EFFICIENCY MODIFICATIONS.
 *
 */
#include <stdio.h>
#include "myfuncts.h"

#define MAX_TESTED 20000  // Not sure how large need to keep testing, so can change if need more

int tri_number(int n); // Return nth triangular number


int main(){
	FILE *output = fopen("output_problem12.txt", "w"); // Writing to output just to be safe
	int nums[8000], *primes, i, input, j;
	int total_divisors = 1;
	j = 0;

	factor *factors;

	primes = era_sieve(nums, 8000);

	for(i = 7; i<MAX_TESTED; i++){
		input = tri_number(i);
		factors = factorize(input, primes);
		while((factors+j)->exponent != -1){
			total_divisors *= ( ((factors+j)->exponent)+1 );
			j++;
		}
		fprintf(output, "%2d has %4d total divisors.\n", input, total_divisors);
		if(total_divisors > 500){
			printf("FOUND IT! %d has %d divisors.\n", input, total_divisors);
			// Will get my attention :)
		}
		total_divisors = 1;
		j =0;
	}

	clean(primes,factors);
	fclose(output);

	return 0;
}

int total_divisors(factor *factors){
	return 0;
}

int tri_number(int n){  // Returns nth triangular number
	return n*(n+1)/2;
}
