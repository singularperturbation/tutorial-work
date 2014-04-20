#ifndef project_euler_prob17
#define project_euler_prob17


#define HUNDRED 7
#define AND 3


// Length for first nineteen integers
extern int oneThroughNineTeen[19];

// Length for ten,twenty,thirty, etc.
extern int specialTensPlace[9];

void assignPlaces(int arg, int *hundreds, int *tens, int *ones);

// Hundreds
int getHundredsLength(int hundredsPlace);

// Tens Place
int getTensLength(int tensPlace);

// Ones Place
int getOnesPlace(int onesPlace);

// Returns length of number as int from int as input
// Range should be 1 to 1000
int getlength(int arg);
#endif
