/*
 * prob12_functs.c
 *
 *  Created on: Aug 12, 2012
 *      Author: ssimmons
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myfuncts.h"

static void initialize_factor_list(int current_length, factor *factors);


void *era_sieve(int input[], int length){
	// More or less adapted from problem 7, but with pointer malloc'd rather than having mostly
	// empty array.
	int *primes = NULL;
	int i=0, j=0, counter=0;
	input[0] = 0;
	input[1] = 0;

	for(i = 2; i<length; i++){ 	// Set all of input array to 1
		input[i] = 1;
	}

	for (i = 2; i< ( (int) ceil(sqrt(length)) ); i++){ // Do actual sieving
			if(input[i] == 1){
				for(j=(i*i); j<length; j += i){
					input[j] = 0;
					counter++;
				}
			}
	}



	primes = (int *) malloc((counter+1)*sizeof(int));
	i = 0, j=0;

	for(i = 2; i<length; i++){
		if(input[i] == 1){
			*(primes+j) = i;
			j++;
		}
	}
	// Now we've set primes to contain all of the prime numbers sieved earlier

	*(primes+j) = 0;


	return primes;

}

void *factorize(int input, int *primes){
	//Use trial divisions to put factors of input as list using primes[]
	//For prob 12, will have max of ~1000 factors as primes will be of length ~1000
	int i=0, counter=0;
	int current_size = MIN_FACTOR_SIZE;

	factor *factors = (factor *) malloc(sizeof(factor)*(MIN_FACTOR_SIZE));
	factors->exponent = 0;
	factors->value = 1;
	initialize_factor_list(current_size, factors);

	while(*(primes+i) != 0){
		while( input % *(primes+i) == 0){
			counter++;
			input /= *(primes+i);
		}

		if((factors+i)->exponent != -1){
			(factors+i)->value = *(primes+i);
			(factors+i)->exponent = counter;

		}
		else{
			current_size += MIN_FACTOR_SIZE;
			factors = realloc(factors, (sizeof(factor)*current_size));
			initialize_factor_list(MIN_FACTOR_SIZE, (factors+i));
			(factors+i)->value = *(primes+i);
			(factors+i)->exponent = counter;
		}


		counter = 0;
		i++;

	}
	return factors;
}

static void initialize_factor_list(int current_length, factor *factors){
	int i;
	for(i = 1; i< (current_length-1); i++){
		(factors+i)->value = 1;
		(factors+i)->exponent = 0;
	}

	(factors+(current_length-1))->value = 1;
	(factors+(current_length-1))->exponent = -1;

	// Initialize pointer to dynamic factor array:
	// By default, factor value == 1 and exponent set to 0,
	// except for last value in array, which is set to -1.

}

void clean(int *primes, factor *factors){
	free(primes);
	free(factors);
}

