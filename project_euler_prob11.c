/*
 * project_euler_prob11.c
 *
 *  Created on: Aug 5, 2012
 *      Author: ssimmons
 *
 *  Problem 11 summary: Find largest product of four
 *  adjacent numbers in 20x20 grid in any direction.
 *
 *	Direction schema:
 *
 *			b	u	s
 *			 ^	^  ^
 *			   \| /
 *		   l<---|--->r
 *			   /|\
 *			  /	v \
 *			t<	d  >a
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BOUNDARY 20

typedef struct d1{
	char points; // Character indicating direction corresponding to
				 // up, down, right, left, and diagonals (u,d,r,l,s,a,t,and b, going
				 // clockwise on diagonals)
} direction;

typedef struct p1{
	int x;
	int y;
} point;


int isvalid_dir(point, direction);  // Returns -1 if invalid, +1 if valid (That is,
									// are there 4 nums including start to multiply along direction?)

int mult_dir(int array[BOUNDARY][BOUNDARY], point, direction);  // Multiplies along specified direction

const static char dirs[] = {'u', 'd', 'r', 'l', 's', 'a', 't', 'b'};  // Shorthand
// Was going to rewrite functs to use for loop with this instead of switch,
// but I thought more explicit treatment was clearer.

void testvalid();  // Tests isvalid_dir function and outputs to file


int main(){
	FILE *input = NULL;
	int i, j, k, nums[BOUNDARY][BOUNDARY], largest, temp;
	largest = 1, temp = 0;

	input = fopen("project_euler_prob11_input.txt", "r");  // open file for reading
	if(input){
		printf("File opened successfully.\n");
	}
	else{
		exit(-1);
	}

	point a;  // Just need one point and one direction
	direction b; // No boy-band jokes here please.

	for(i =0; i<BOUNDARY; i++)
		for(j = 0; j<BOUNDARY; j++)
			fscanf(input, "%d", &nums[i][j]);  // Read data from file into array

	fclose(input);
	largest =1;
	for (k = 0; k<8; k++){
		b.points = dirs[k];
		for(i = 0; i<BOUNDARY; i++){
			for(j = 0; j<BOUNDARY; j++){
				a.x = j;
				a.y = i;
				if(isvalid_dir(a,b) > 0 ){ // Is this a valid origin + dir combo?
					temp = mult_dir(nums,a,b);
					largest = (temp > largest) ? temp : largest;
				}
			}
		}
	}

	printf("The largest multiple of 4 adjacent numbers in 20x20 array is: %d\n", largest);

	//testvalid();
	return 0;
}

int isvalid_dir(point a, direction b){  // Returns -1 if invalid, +1 if valid
	switch(b.points){					// Used to tell if need to multiply along given										// direction
		case 'u':						// direction.
			if( ( (a.y - 3 ) > -1) )
					return 1;
			return -1;
		case 'd':
			if ( (a.y + 3) < BOUNDARY)
				return 1;
			return -1;
		case 'r':
			if((a.x + 3) < BOUNDARY)
				return 1;
			return -1;
		case 'l':
			if((a.x -3) > -1)
				return 1;
			return -1;
		case 's':
			if (((a.x +3) < BOUNDARY) && ((a.y -3) > -1))
				return 1;
			return -1;
		case 'a':
			if (((a.x +3) < BOUNDARY) && ((a.y +3) < BOUNDARY))
				return 1;
			return -1;
		case 't':
			if (((a.x - 3) > -1) && ((a.y +3) < BOUNDARY))
				return 1;
			return -1;
		case 'b':
			if (((a.x - 3) > -1) && ((a.y - 3) > -1))
				return 1;
			return -1;

		default: printf("Invalid direction!\n");
			return -1;
	}
}

int mult_dir(int array[BOUNDARY][BOUNDARY], point a, direction b){
	// Return multiple along given direction starting from
	// array[a.y][a.x] as starting point.
	// Can assume that has already been checked for validity.
	int temp = 1, i = 0;
	switch(b.points){
	case 'u':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) - i][a.x];
		}
		return temp;
	case 'd':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) + i][a.x];
		}
		return temp;
	case 'r':
		for(i = 0; i<4; i++){
			temp *= array[(a.y)][(a.x)+i];
		}
		return temp;
	case 'l':
		for(i = 0; i<4; i++){
			temp *= array[(a.y)][(a.x)-i];
		}
		return temp;
	case 's':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) -i][(a.x)+i];
		}
		return temp;
	case 'a':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) +i][(a.x)+i];
		}
		return temp;
	case 't':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) +i][(a.x)-i];
		}
		return temp;
	case 'b':
		for(i = 0; i<4; i++){
			temp *= array[(a.y) -i][(a.x)-i];
		}
		return temp;

	default: printf("Invalid direction!\n");
		return 0;
	}
}

void testvalid(){
	// What this function does:
	/* Uses a series of nested loops to check 20x20 coordinates
	 * and each direction for 'validity' at point as defined by isvalid_dir(point a, direction b).
	 *
	 * Really, this is just checking the isvalid_dir function.
	 * Run it and you'll see what I mean.
	 */
	FILE *output;
	output = fopen("project_euler_prob11_output.txt", "w");
	int i, j,k;
	point a;
	direction b;

	for(k=0; k<8; k++){
		b.points = dirs[k];
		fprintf(output, "\nDirection is %c below: \n\n", b.points);
		for (i = 0; i<BOUNDARY; i++){
			for(j=0; j<BOUNDARY; j++){
				a.x = j;
				a.y = i;
				fprintf(output, "%2d\t", isvalid_dir(a,b) );
			}
			fprintf(output, "\n");
		}
	}
	fclose(output);
}
