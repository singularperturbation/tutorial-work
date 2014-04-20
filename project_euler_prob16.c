/*
 * project_euler_prob16.c
 *
 *  Created on: Aug 23, 2012
 *      Author: ssimmons
 *
 *  Problem 16: Find sum of digits for
 *  2^1000.
 *
 *  Problem 15 done analytically (combinatorics!)
 *  so no source code.
 *
 *  Learning how to use gmp lib here (as 2^1000 *very* big)
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#define SIZE 150

int sum_array(char *);

int main(){
	char *digits = NULL;
	mpz_t answer;
	mpz_init(answer);
	mpz_ui_pow_ui(answer,2,1000);
	digits = mpz_get_str((char *) NULL,10,answer);

	printf("%s\n", digits); // debugging

	mpz_clear(answer);
	printf("The answer is: %d\n", sum_array(digits));
	free(digits);
	return 0;
}

int sum_array(char *input){
	int i = 0, sum = 0;
	if (input == NULL)
		return sum;
	while(*(input+i) != '\0'){
		sum += *(input+i) - '0';
		i++;
	}

	return sum;
}
