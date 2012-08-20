/*
 * project_euler_prob13.cc
 *
 *  Created on: Aug 17, 2012
 *      Author: ssimmons
 *
 * Find sum of 100 50 digit numbers, return first ten digits.
 *
 * Very simple program design (famous last words, I know), so not going
 * into whole lot of planning here.
 *
 * Will read in data to array and then implement arithmetic to sum them all.
 */

#include <stdio.h>
#include <stdlib.h>

#define ESTIMATED_MAX 60  // max # of digits

void addrows(int nums[][50], int rownum, int *sum);
void printnum(int *sum);

int main(){
	FILE *input;
	int i, j, nums[100][50];
	int *sum = NULL;
	char line[50];

	for (i = 0; i < 50; i++)
		line[i] = '0';

	input = fopen("project_euler_prob13_input.txt", "r");
	if(input == NULL)
		exit(-1);

	for (i = 0; i<100; i++){
		fscanf(input, "%s%*c", line); // Reads in line ignoring \n, \t
		for(j = 0; j<50; j++){
			nums[i][j] = (int) (line[j] - '0');
		}
	}
	// Now we've loaded all numbers into array


	fclose(input);

	sum = (int *) malloc(sizeof(int)*ESTIMATED_MAX);

	for(i = 0; i<ESTIMATED_MAX; i++)
		sum[i] = 0;


	// Need to sum numbers by implementing arithmetic
	// Basic rules: digit1[i] = digit1[i] + digit2[i] if sum < 10
	// If sum > 10, digit1[i-1] += 1; digit1[i] = digit1[i] + digit2[i] - 10;
	/* for (i = 0; i<50; i++)
	 * 		addrows(nums[i][100], sum);
	 *
	 */
	for(i = 0; i<100; i++)
		addrows(nums, i, sum);

	printf("The total sum of all 100 50-digit nums is: \n");
	printnum(sum);
	free(sum);
	return 0;
}

void addrows(int nums[100][50], int rownum, int *sum){
	// Make 49 of sum correspond to 39 of nums[rownum][39], and so forth
	int temp, i;
	for(i = 49; i>-1; i--){
		temp = nums[rownum][i] + *(sum+i+10);
		if(temp > 9){
			*(sum+i+9) += 1;
			*(sum+i+10) = (temp - 10);
		}
		else{
			*(sum+i+10) = temp;
		}
	}


}

void printnum(int *sum){
	int i = 0;
	// Skip over any leading zeros
	while(*(sum+i) == 0){
		i++;
	}

	for(; i<ESTIMATED_MAX; i++)
		printf("%d", *(sum+i));

	printf("\n");
}

