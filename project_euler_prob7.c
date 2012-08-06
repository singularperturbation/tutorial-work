/*
 * project_euler_prob7.c
 *
 *  Created on: Jul 20, 2012
 *      Author: ssimmons
 *
 *  Find the 10,001st prime number
 *
 *  "Sift the Two's and Sift the Three's,
 *  The Sieve of Eratosthenes.
 *  When the multiples sublime,
 *  The numbers that remain are Prime."
 *  --Anonymous
 *
 */


#include <stdio.h>
#include <math.h>

#define LENGTH 500000

int main(){
	int candidates[LENGTH];
	int i, j;
	j = 0;

	// Initialize array
	candidates[0] = 0;
	candidates[1] = 0;

	for (i = 2; i<LENGTH; i++)
		candidates[i] = 1;

	// Do sieving such that all 'true' (== 1) are now prime
	for (i = 2; i< ( (int) ceil(sqrt(LENGTH)) ); i++){
		if(candidates[i] == 1){
			for(j=(i*i); j<LENGTH; j += i){
				candidates[j] = 0;
			}
		}
	}
	// Now count # of primes up to 10,001st
	j = 0;
	for (i = 2; i< LENGTH; i++){
		if(candidates[i] == 1){
			j++;
			if(j == 10001){
				printf("The 10001st prime is: %d", i);
				break;
			}
		}
	}
	return 0;
}
