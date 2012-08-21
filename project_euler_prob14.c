/*
 * project_euler_prob14.c
 *
 *  Created on: Aug 20, 2012
 *      Author: ssimmons
 *
 * Find largest "starting number" < 1,000,000
 * that ultimately converges to 1 using Collatz
 * Conjecture rules.
 *
 * If n == even -> n/2
 * If n == odd -> 3n + 1
 *
 * Plan:  Will consider brute-forcing as first approach.
 */

#include <stdio.h>
int isodd(long int input);

int main(){
	long int i, temp, counts=1, counts_max=1, num_max=1;

	for(i = 999999; i>0; i--){
		temp = i;
		printf("%ld\n", i);
		while(temp != 1){
			if(isodd(temp)){
				temp = 3*temp + 1;
				counts++;
			}
			else{
				temp /= 2;
				counts++;
			}
		}
		if(counts>counts_max){
			counts_max = counts;
			num_max = i;
		}
		counts = 1;
	}
	printf("The maximum number of counts to get to 1 from a number < 1e6 is: %ld\n", counts_max);
	printf("This max is reached when considering: %ld\n", num_max);

	return 0;
}


int isodd(long int input){
	if( (input % 2) == 0)
		return 0;
	return 1;
}
