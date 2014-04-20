/* Project Euler Problem 17
 * project_euler_prob17.c
 * 
 * Created on: April 19, 2014
 * Author: ssimmons
 *
 * Problem:
 * Find total length of numbers from 1 to 1000 when written out as numbers.
 * We will use hyphens between tens-ones and 'and' between the hundreds place
 * and the remainder (103 == one hundred and three)
 * 142 == (one hundred and forty-two)
 *
 * hypens and spaces do not count towards length
 *
 *
 */

#include <stdio.h>
#include "project_euler_prob17.h"

int main(){
  int total_length = 0;
  
  int i;

  for (i = 1; i<1001; i++){
    total_length += getlength(i);
  }

  printf("%d\n",total_length);
  
  return 0;
}
