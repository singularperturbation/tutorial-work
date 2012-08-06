/*
 * project_euler_prob1.c
 *
 *  Created on: Jul 9, 2012
 *      Author: ssimmons
 */
#include <stdio.h>
#include <math.h>

int sumlist(int list[], int length);
void removedupes(int list1[], int length1, int list2[], int length2, int output[]);
// Need to find sum of all multiples of 3 or 5 below one thousand
	/* Plan:
	 * Get multiples of 3 in list
	 * Get multiples of 5 in list
	 * Find duplicates and remove from one list (replace w/ zero)
	 * Sum each list, then add sums, removing sum of dupes
	 */
// NOTE: INEFFICIENT!!  USE NUMBER % 3 || NUMBER % 5 == 0 WITH SIMPLE LOOP

int main(){

	int multsof3[333];
	int multsof5[199];
	int dupes[200];
	int i, j, output;

	for (i = 1; i < 334; i++){
		multsof3[(i-1)] = 3*i;
	}

	for (j = 1; j < 200; j++){
		multsof5[(j-1)] = 5*j;
	}

	removedupes(multsof3, i-1, multsof5, j-1, dupes);
	output = sumlist(multsof3, i-1) + sumlist(multsof5, j-1) - sumlist(dupes, j-1);
	printf("The sum of all multiples of 3 and multiples of 5 below a thousand is: %d", output);



/*	printf("Checking sumlist function: \n");
	int temp = 0;
	int list[6] = {3,6,9,12,15,18};
	temp = sumlist(list, 6);
	printf("The sum of list should be 63, but it is reported as %d\n", temp);
*/

/*
	// Checking remove dupes:
	int i = 0;
	int list1[11] = {3,6,9,12,15,18,21,24,27,30,33};
	int list2[6] = {5,10,15,20,25,30};
	int dupes[6] = {0,0,0,0,0,0};
	removedupes(list1, 11, list2, 6, dupes);
	for(i = 0; i<6; i++){
		printf("The %d th dupes array is: %d\n", i, dupes[i]);
	}
	printf("The sum should be 258\n");
	printf("The sum is in fact: %d", (sumlist(list1,11)+sumlist(list2,6)-sumlist(dupes,6)) );

*/
	return 0;




}

int sumlist(int list[], int length){
	int i, sum;
	sum = 0;
	for (i = 0; i< length; i++){
		sum += list[i];
	}
	return sum;
}

void removedupes(int list1[], int length1, int list2[], int length2, int output[]){
	int i, j, matches = 0, output_counter = 0;
	for (i = 0; i < length1; i++){
		for (j = 0; j < length2; j++){
			if (list1[i] == list2[j])
				matches = 1;
		}
		if (matches == 1){
			output[output_counter] = list1[i];
			output_counter++;

		}
		matches = 0;
	}

	for (i = output_counter; i < length2; i++){
		output[i] = 0;
	}
}
