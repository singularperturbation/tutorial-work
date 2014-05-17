/*
 * project_euler_prob4.c
 *
 *  Created on: Jul 12, 2012
 *      Author: ssimmons
 *
 *  Problem 4:
 *  Find largest palindrome made from 2 three digit numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int array[], int left, int right);
void swap(int array[], int i, int j);
int ispalindrome(int input); // Returns 1 if palindrome, -1 if not

int main(){
	/* Solving this: generate list of numbers, test for 'palindromicity',
	 * and then sort with qsort implementation.
	 */

	/* Testing sorting:  IT WORKS
	int new[10] = {2, 3, 5, 7, 4, 1, 9, 10, 6, 8};
	int i = 0;
	printf("Unsorted.\n");
	for (i = 0; i < 10; i++){
		printf("%d\n", new[i]);
	}

	printf("Sorted!\n");
	qsort(new, 0, 9);
	for (i = 0; i < 10; i++){
		printf("%d\n", new[i]);
	}
	*/

	int *palindromes;
  palindromes = (int *) calloc(sizeof(int) * 2000,sizeof(int));

	int i,j, temp, counter, numpals;

	for (i = 0; i<2000; i++){
		palindromes[i] = 0;
	}

	counter = 0;
	numpals = 0;
	printf("Starting multiplication process.\n");

	for (i = 999; i>99; i--){
		for(j = (999-counter); j>99; j--){
			temp = i*j;
			if(ispalindrome(temp)>0){
				palindromes[numpals] = temp;
				numpals++;
			}
		}
		counter++;
	}

	printf("Now sorting!\n");

	quicksort(palindromes, 0, 1999);

	printf("The largest are:\n");
	printf("%d\n", palindromes[1999]);
	printf("%d\n", palindromes[1998]);
	printf("%d\n", palindromes[1997]);

  free(palindromes);

	return 0;
}

int ispalindrome(int inputnum){
	char* a = (char*) malloc(sizeof(char)*10);
	sprintf(a, "%d", inputnum);
	int i, MAXLEN;
	for (i = 0; (*(a+i) != '\0'); i++){
		;
	}

	// i is now the length of the array
	MAXLEN = i;
	for (i = 0; i <= ( (MAXLEN/2) - 1); i++){
		if (*(a+i) != *(a+( (MAXLEN-1) -i ) ) ){
			free(a);
			return -1;
		}
	}
	free(a);
	return 1;  // all of these are identical, it *is* a palindrome
}

void quicksort(int v[], int left, int right){
	int i, last;
	if (left >= right) /* do nothing if array contains */
		return;        /* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
	last = left;
	/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
	quicksort(v, left, last-1);
	quicksort(v, last+1, right);

}

void swap(int v[], int i, int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
