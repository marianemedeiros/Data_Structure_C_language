/*
   Copyright (C) 2014, Guilherme Castro Diniz.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation (FSF); in version 2 of the
   license.

   This program is distributed in the hope that it can be useful,
   but WITHOUT ANY IMPLIED WARRANTY OF ADEQUATION TO ANY
   MARKET OR APPLICATION IN PARTICULAR. See the
   GNU General Public License for more details.
   <http://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Search for a specific number in a vector ordained.
 *
 * @param int number, number which will be searched in the vector..
 * @param int* vector, vector ordained.
 * @oaram int begin, the value of the beginning of thevector.
 * @param int end, the value of the end of the vector.
 *
 * @returns the number wanted.
 */
int binarySearch(int number, int* vector, int begin, int end){
	if (begin > end){
		return -1;   
	}
	int middle = (begin + end) / 2;
	if (vector[middle] == number){
		return middle;
	}
	if (number > vector[middle]){
		return binarySearch(number, vector,middle + 1, end);
	}
	else{
		return binarySearch(number, vector, begin, middle - 1);
	}
}
int main(){
	int sizeVector, i, number;
	int* vector;

	printf("Enter the size of the vector of search: ");
	scanf(" %d", &sizeVector);
	if(sizeVector < 0){
		printf("Invalid value!\n");
		return 0;
	}
	else{
		vector = (int*) calloc(sizeVector, sizeof(int));
		for(i = 0; i <= sizeVector; i++){
			vector[i] = i;	
		}
	}

	printf("Enter the number there be sought: ");
	scanf(" %d", &number);

	if (number < 0 || number > sizeVector){
		printf("Invalid number!\n");
		return 0;
	}

	printf ("The value is: %d \n", binarySearch(number, vector, 0, sizeVector));
	return 0;
}
