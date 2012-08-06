/*
 * project_euler_prob6.c
 *
 *  Created on: Jul 19, 2012
 *      Author: ssimmons
 *  Returns difference between sum of squares and square of sum of numbers 1-100
 */

#include <stdio.h>
#include <math.h>

int main(){
	int squareofsum = (5050*5050); // a priori knowledge
	int sumofsquares = 0, i;
	for (i = 1; i<101; i++)
		sumofsquares += i*i;

	printf("The difference is: %d\n", (squareofsum-sumofsquares));

	return 0;
}


// Can do more smartly by realizing undetermined coefficient cubic polynomial will give
// Sum of squares from 1 to n
