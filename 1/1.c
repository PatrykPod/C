/*
 * File 1.c
 * 
 * This file contains the code for assignment 1. It calculates an
 * approximation of the number pi. Testing if random coördinates are in
 * a circel with radius 1. 
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 10-02-2012
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if (argc < 2){
		printf("You forgot the parameter. The syntax for the program ");
		printf("is:\n./pi times\n");
	}
	else{
		double a, b, c, pi, hits = 0;
		int i, times = atoi(argv[1]);
		if (times < 1)
			printf("Use positive numbers only\n");
		else{
			/*
			 * Test using pythagoras if the coördinates are inside the
			 * circle.
			 */
			for (i = times; i; i--){
				a = (double)rand()/RAND_MAX;
				b = (double)rand()/RAND_MAX;
				c = a*a + b*b;
				if(c < 1.0)
					hits++;
			}
			pi = 4*(hits/times);
			printf("pi = %f\n", pi);
		}
	}
	return(0);
}
