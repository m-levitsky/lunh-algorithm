/*
 * functions.h
 *
 *  Created on: Aug 4, 2019
 *      Author: qwertymaden
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdbool.h>

int digitsCount(int n)
{
	int count = 0;

	  do {
	    n /= 10;
	    count++;
	  } while(n!= 0);

	  return count;
}

void arrInit(int n, int arr[], int count)
{
	 for (int i = count-1; i >= 0; --i)
	    {
	    		arr[i] = n %10;
	    		n  /= 10;
	    }
}

/* main part of algorithm is described here */
bool validate(long num)
{

	int count = digitsCount(num);
    int arr[count];
    arrInit(num, arr, count);

    /* Double every other digit, scanning from right to left,
     starting from the second digit (from the right) */

     for (int i = count-2; i >= 0; i -= 2){

    	 	arr[i] *= 2;

    	 	/* If a resulting number is greater than 9,
    	 	  replace it with the sum of its own digits  */

    	 	if(arr[i] > 9)
    	 	{
    	 		arr[i] = (arr[i] % 10) + (arr[i] / 10);
    	 	}

     }


     long sum = 0;

     /* Sum all of the final digits */

     for (int i = 0; i < count; i++) sum += arr[i];

     /* If the remainder equals zero,
		the original credit card number is valid. */

     return (sum % 10 == 0)? 1 : 0;

}

void test(long n, bool expected)
{
	if (validate(n) == expected) printf("Test for %ld passed \n", n);
	else {
		fprintf(stderr, "Test for %ld failed \n", n);
	}
}

#endif /* FUNCTIONS_H_ */
