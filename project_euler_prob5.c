/*
 * project_euler_prob5.c
 *
 *  Created on: Jul 18, 2012
 *      Author: ssimmons
 *
 *  Find smallest number evenly divisible by all numbers <= 20
 *  Note: 2520 == smallest number evenly divisible by 1-10
 */


#include <stdio.h>
#include <math.h>
void trialdivision(int input, int primes[], int output[]);

int main(){
	int primes[8] = {2,3,5,7,11,13,17,19};
	int composites[11] = {4,6,8,9,10,12,14,15,16,18,20};
	int factors[4] = {1,1,1,1};  // Should be sufficient up to 20 as 16 has most: 2x2x2x2
	int temp, answer = 1;

	int j = 0, i = 0;

	for (i = 0; i<8; i++){
		answer *= primes[i];
	}


	/*
	 * Testing factorization of 12: array should be 2*2*3*1
	i = 12;
    trialdivision(i, primes, factors);
    printf("12 has been factored.\n");
    for (i = 0; i<4; i++){
    	printf("Factor %d of 12 is: %d\n", i, factors[i]);
    }
    * This works!
    *
    */


	for (i = 0; i<11; i++){
		trialdivision(composites[i], primes, factors);
		// It's okay if factors isn't 'cleaned' multiple times as temp will
		// still be divisible by former factors and less computation to leave in
		temp = answer;
		for (j = 0; j<4; j++){
			if( (temp % factors[j]) == 0){
				temp /= factors[j];
			}
			else{
				answer *= factors[j];
			}
		}

	}

	printf("The lowest number evenly divisible by 1-20 is: %d\n", answer);


	return 0;
}

// Factors input with primes list primes and output array output
void trialdivision(int input, int primes[], int output[]){
	int i, counter;
	counter = 0;
	for (i = 0; i < 3; i++){  // Only need first 3 up to n = 48
		if ((primes[i]*primes[i]) > input)
			break;
		while( (input % primes[i]) == 0){
			output[counter] = primes[i];
			counter++;
			input /= primes[i];
		}

	}
	if(input > 1)
		output[(++counter)] = input;

}


