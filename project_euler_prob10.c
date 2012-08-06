/*
 * project_euler_prob10.c
 *
 *  Created on: Aug 5, 2012
 *      Author: ssimmons
 *
 * Find sum of primes < 2*10^6
 * Strategy: Using sieve of Eratosthenes
 * to get primes, then sum.
 *
 * Note: Previous problem solved analytically before
 * got around to writing a program that worked.
 *
 * Due to frustration, it will now not be written.
 */
#include <stdio.h>
#include <math.h>

#define LENGTH 2000000

long int sumnums(int input[]);

int main(){
	int nums[LENGTH], i, j;
	long int output;
	nums[0] = 0;
	nums[1] = 0;


	for (i = 2; i<LENGTH; i++)
		nums[i] = 1;

	for (i = 2; i< ( (int) ceil(sqrt(LENGTH)) ); i++){
			if(nums[i] == 1){
				for(j=(i*i); j<LENGTH; j += i){ // j = i*i to start with as starting lower
					nums[j] = 0;				// already done by sieving other primes
				}
			}
	}
	output = sumnums(nums);
	printf("The sum of all primes below 2 million is: %ld\n", output);

	return 0;
}


long int sumnums(int input[]){
	int i;
	long int temp;
	for (i = 0; i<LENGTH; i++){
		if(input[i] == 1)
			temp += i;
	}
	return temp;
}
