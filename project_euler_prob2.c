/*
 * project_euler_prob2.c
 *
 *  Created on: Jul 9, 2012
 *      Author: ssimmons
 *
 *  Problem summary:
 *  Find the sum of even-value Fibonacci terms below four million.
 */

#include <stdio.h>
#include <math.h>

int main(){
	long int fib[2] = {1,1};
	long int temp = 0;
	long int evensum = 0;
	while(fib[1] < 4000000){
		if( (fib[1] % 2) == 0)
			evensum += fib[1];
		temp = fib[1] + fib[0];
		fib[0] = fib[1];
		fib[1] = temp;

	}
	printf("The sum of the even fibonacci numbers is: %ld\n", evensum);
	return 0;
}

