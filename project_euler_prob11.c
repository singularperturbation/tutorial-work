/*
 * project_euler_prob11.c
 *
 *  Created on: Aug 5, 2012
 *      Author: ssimmons
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct d1{
	char points; // Character indicating direction corresponding to
				 // up, down, right, left, and diagonals (u,d,r,l,s,a,t,and b, going
				 // clockwise on diagonals)
} direction;

typedef struct p1{
	int x;
	int y;
} point;


int isvalid_dir(point, direction);  // Returns -1 if invalid, +1 if valid

int mult_dir(int array[20][20], point, direction);  // Multiplies along specified direction

int main(){
	FILE *input = NULL;
	int i, j, nums[20][20];
	const static char dirs[] = {'u', 'd', 'r', 'l', 's', 'a', 't', 'b'};
	// This will make it easier to specify directions

	input = fopen("project_euler_prob11_input.txt", "r");  // open file for reading
	if(input){
		printf("File opened successfully.\n");
	}
	else{
		exit(-1);
	}

	point a;  // Just need one point and one direction
	direction b; // No boy-band jokes here please.

	for(i =0; i<20; i++)
		for(j = 0; j<20; j++)
			fscanf(input, "%d", &nums[i][j]);  // Read data from file into array

	fclose(input);
	// Just testing functions
	for(i = 0; i<8; i++){
		b.points = dirs[i];
		mult_dir(nums, a, b);
	}

	b.points = 'w';
	mult_dir(nums,a,b);

	return 0;
}

int isvalid_dir(point a, direction b){  // Returns -1 if invalid, +1 if valid
	switch(b.points){					// Used to tell if need to multiply along given										// direction
		case 'u':						// direction.
			if( ( (a.y - 4 ) > -1) )
					return 1;
			// no break needed
		case 'd':
			printf("Direction is down!\n");
			break;
		case 'r':
			printf("Direction is right!\n");
			break;
		case 'l':
			printf("Direction is left!\n");
			break;
		case 's':
			printf("Direction is northeast\n");
			break;
		case 'a':
			printf("Direction is southeast\n");
			break;
		case 't':
			printf("Direction is southwest\n");
			break;
		case 'b':
			printf("Direction is northwest\n");
			break;

		default: printf("Invalid direction!\n");
			return -1;
			// no break
	}
	return -1;
}

int mult_dir(int array[20][20], point a, direction b){
	// Return multiple along given direction starting from
	// array[a.y][a.x] as starting point.
	switch(b.points){
	case 'u':
		printf("Direction is up!\n");
		break;
	case 'd':
		printf("Direction is down!\n");
		break;
	case 'r':
		printf("Direction is right!\n");
		break;
	case 'l':
		printf("Direction is left!\n");
		break;
	case 's':
		printf("Direction is northeast\n");
		break;
	case 'a':
		printf("Direction is southeast\n");
		break;
	case 't':
		printf("Direction is southwest\n");
		break;
	case 'b':
		printf("Direction is northwest\n");
		break;

	default: printf("Invalid direction!\n");
		// no break
	}
	return 0;
}
