/*
 * project_euler_prob8.c
 *
 *  Created on: Jul 22, 2012
 *      Author: ssimmons
 *
 *  Find greatest multiple of five consecutive digits in
 *  1000 digit number.
 *
 *  Note: input file is: project_euler_prob8_input.txt
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>


// Need to implement singly linked list.

typedef struct l1 link;

struct l1{
	int numvalue;
	link *next;
};

typedef struct{
	link *first;
	link *last;
} list;

// Don't need array of link pointers to initiate, just
// create list and initialize through adding integers

void pop(list *);
void push(list *, link *);
int productlist(list *);

int main(){
	FILE *input;
	int i = 0, product = 1, counter = 5;
	char *line = (char *) malloc((sizeof(char)*100));
  // Keep origPointer so that can free line
  // We fgets(line) until it's null, so no way to free
  // unless we save the original memory location somewhere
  // or structure loop differently.
  char *origPointer = line;
	link *templinks[5];
	list working_numbers;

	input = fopen("project_euler_prob8_input.txt", "r");

	if (errno == ENOENT){
		printf("File does not exist!\n");
		fclose(input);
		return -1;
	}
	for (i = 0; i<5; i++)
		templinks[i] = (link *) malloc(sizeof(link));
	// WILL NEED TO FREE THESE!

	// Use fgets to read character at a time
	line = fgets(line, 100, input);

	templinks[0]->numvalue = line[0] - '0';
	templinks[1]->numvalue = line[1] - '0';
	templinks[2]->numvalue = line[2] - '0';
	templinks[3]->numvalue = line[3] - '0';
	templinks[4]->numvalue = line[4] - '0';

	working_numbers.first = templinks[0];
	working_numbers.last = templinks[1];
	working_numbers.first->next = working_numbers.last;

	push(&working_numbers, templinks[2]);
	push(&working_numbers, templinks[3]);
	push(&working_numbers, templinks[4]);

	product *= productlist(&working_numbers);

	printf("The product of the first five is: %d\n", product);

	while(line != NULL){

		while(line[counter] != '\n'){
			link *temp = working_numbers.first;
			pop(&working_numbers);
			temp->numvalue = line[counter] - '0';
			temp->next = NULL;
			push(&working_numbers, temp);
			i = productlist(&working_numbers);

			if(i>product)
				product = i;

			counter++;


		}
		counter = 0;
		line = fgets(line, 100, input);
	}

	printf("The max product of five consecutive digits is: %d\n", product);

	for (i = 0; i<5; i++)
		free(templinks[i]);

	free(origPointer);
	fclose(input);

	return 0;
}


void pop(list *input){
	input->first = (input->first)->next;
	//free(temp);  Don't free, will reuse
}

void push(list *input_list, link *to_add){
	// This assumes list already has at least a first
	// and last member, will have to add those two manually.
	(input_list->last)->next = to_add;
	to_add->next = (link *) NULL;
	input_list->last = to_add;
}

int productlist(list *input){
	int product = 1;
	link *temp;
	for(temp = input->first; (temp != NULL); temp = temp->next)
		product *= temp->numvalue;

	return product;
}
