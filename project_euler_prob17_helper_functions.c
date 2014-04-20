#include <stdio.h>
#include <assert.h>
#include "project_euler_prob17.h"

int specialTensPlace[] = {3,6,6,5,5,5,7,6,6};
int oneThroughNineTeen[] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

void assignPlaces(int input, int *hundreds, int *tens, int *ones){
  if (input >= 100){
    *hundreds = input/100;
  }
  else{
    *hundreds = 0;
  }
  if (input >=10){
    *tens = (input - ( (*hundreds) * 100) ) / 10;
  }
  else{
    *tens = 0;
  }

  *ones = input - ( ((*hundreds) * 100) + ( (*tens) * 10));
}

int getHundredsLength(int hundredsPlace){
  // Input should be integer between zero and nine (inclusive)
  assert( (hundredsPlace >= 0) && (hundredsPlace <= 9));
  if (hundredsPlace == 0){
    // Want to handle case where not sure if num > 100
    return 0;
  }
  else{
    return oneThroughNineTeen[hundredsPlace-1];
  }
}

int getTensLength(int tensPlace){
  // Input should be integer between zero and nine (inclusive)
  assert( (tensPlace >= 0) && (tensPlace <= 9));
  if (tensPlace == 0){
    return 0;
  }

  return specialTensPlace[tensPlace-1];
}

int getOnesPlace(int onesPlace){
  // Input should be integer between zero and nine (inclusive)
  assert( (onesPlace >= 0) && (onesPlace <= 9));
  if (onesPlace==0){
    return 0;
  }

  return oneThroughNineTeen[onesPlace-1];
}

int getlength(int arg){

  int totLength;
  int hundreds,tens,ones;
  hundreds = tens = ones = totLength = 0;

  // First do handling of special cases:
  // 1000 == 'one thousand' == 11
  // One through nineteen have values mapped by array

  if (arg > 1000)
    return 0;

  if (arg == 1000){
   return 11;
  }

  
  assignPlaces(arg,&hundreds,&tens,&ones);

  if ( (arg % 100) <= 19){
    totLength = oneThroughNineTeen[  ( ( tens* 10 ) + ones ) -1  ];
    if ( arg >= 100){
      totLength += HUNDRED;
      totLength += getHundredsLength( hundreds);
      //totLength += oneThroughNineTeen[(hundreds -1)];

      if ( (ones != 0) || (tens != 0) ){
        totLength += AND;
      }
      
    }
    return totLength;
  }

  totLength = getHundredsLength(hundreds) + getTensLength(tens) + getOnesPlace(ones);
  if ( (arg >= 100) ){
    totLength += HUNDRED;
    if ( (tens>0) || (ones>0) ){
      totLength += AND;
    }
  }
  return totLength;
}
