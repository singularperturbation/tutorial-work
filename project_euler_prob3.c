/*
 * project_euler_prob3.c
 *
 *  Created on: Jul 9, 2012
 *      Author: ssimmons
 *
 *  Problem 3:
 *  Find largest prime factors of a number.
 *  (The number is: 600851475143)
 */

// Using trial division, as don't want to implement Gaussian elimination to do
// a more advanced technique.

// SCREW EVERYTHING!!  USING TRIAL DIVISION!

#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define INPUT 600851475143

int main(){
/*	long int lowerb;
	lowerb = (long int) floor(sqrtl(INPUT));
	printf("The smoothness bound is: %ld\n", lowerb);
*/
	// Want to practice reading lines
	FILE *input;
	input = fopen("100000.txt", "r");
	if (input == NULL){
		printf("ERROR!\n");
		return -1;
	}

	int temp[9];
	int i = 0;
	int counter = 0;
	int primes[100008];

	for (i = 0; i<9; i++){
		temp[i] = 0;
	}
	for (i = 0; i<100008; i++){
		primes[i] = 0;
	}

	while(	fscanf(input, "%d%d%d%d%d%d%d%d%d", temp, temp+1, temp+2, temp+3, temp+4, temp+5, temp+6, temp+7, temp+8) != EOF){
		for (i = 0; i<9; i++){
				primes[(i+counter)] = temp[i];
		}
		counter += 9;
	}
	fclose(input);

	counter = 0;

	int factors[10][2];
	for (i = 0; i<10; i++){
		factors[i][0] = 0;
		factors[i][1] = 0;
	}

	// Using counter to keep track of position in factor array
	long int n = INPUT;

	for (i = 0; i <100008; i++){

		if (primes[i]*primes[i]>INPUT)
			break;

		factors[counter][0] = primes[i];

		while((n % primes[i]) == 0){
			factors[counter][1] += 1;
			n = n/primes[i];
		}

		if(factors[counter][1] > 0)
			counter++;
	}

	// Remove bug at end
	if((n % factors[counter][0]) != 0 )
		factors[counter][0] = 0;

	// Now to print out factor list
	for (i = 0; i<10; i++){
      if ( (factors[i][0] == 0) || factors[1][0] == 0) break;
			printf("%ld may be factored %d times by %d.\n", INPUT, factors[i][1], factors[i][0]);
	}


	return 0;
}
