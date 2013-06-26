#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ITERATIONS 100000000
/* Overall, this is just a quick-and-dirty
 * Monte carlo way of estimating Pi by seeing the proportion of
 * points that fall within the area of a square from (0,0) to (2,2)
 */

typedef struct{
	double x;
	double y;
} point;

// Returns 1 if the point is in the boundaries of the circle.
int inBounds(point in){
	if (sqrt( pow((in.x - 1),2) + pow((in.y -1),2) ) <= 1.0)
		return 1;
	return 0;
}

double my_rand(){
	// Want to return a number between 0 and 2
	return (double) ( (double) rand() / (double) (RAND_MAX/2));
}

long double estimatePi(long double input_ratio){
	// Ratio == points inside / points outside
	// Square is 2x2, while circle has radius of 1
	// So ratio should be Pi/4
	return (long double) input_ratio*4;
}

int main(int argc, char *argv[]){
	int i,seed,pointsIn = 0,totPoints = 0;
	sscanf(argv[1],"%d",&seed);
	printf("Seed: %d\n",seed);
	long double ratio;
	srand(seed);
	point dartboard;
	for(i = 0; i<ITERATIONS; i++){
		dartboard.x = my_rand();
		dartboard.y = my_rand();
		if ( (inBounds(dartboard)) == 1)
			pointsIn++;
		totPoints++;
	}
	ratio = (double) pointsIn / (double) totPoints;
	printf("Ratio: %Lf\n",ratio);
	printf("Estimate of Pi: %Lf\n",estimatePi(ratio));
	return 0;
}
