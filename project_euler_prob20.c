/*
 * project_euler_prob20.c
 *
 * Created on: April 27, 2014
 * Author: ssimmons
 *
 * Problem 20: Find sum of digits
 * for 100!
 *
 * Copy sum function from problem 16
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int sum_array(char *);

int main(){

  char *digits = NULL;
  unsigned long int i = 1;

  mpz_t output;
  mpz_init(output);
  // Could do this with builtin function
  // mpz_fac_ui
  mpz_set_ui(output,1);

  for (i = 1; i<101; i++){
    mpz_mul_ui(output,output,i);
  }

  digits = mpz_get_str( (char * ) NULL, 10 , output);
  mpz_clear(output);

  printf("The answer is %d \n", sum_array(digits));

  free(digits);
  return 0;
}

int sum_array(char *input){
  int i = 0, sum = 0;
  if (input == NULL)
    return sum;

  while(*(input+i) != '\0'){
    sum += *(input+i) - '0';
    i++;
  }

  return sum;
}
