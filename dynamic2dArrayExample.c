#include <stdlib.h>
#include <stdio.h>
const int n = 2; //second dimension for range array, eg [0, 1]


//param arr is an array with an unspecified number of n-element arrays
//param m is the number of n element arrays
//so arr is m x n
int dynamic2dArrayExample( int arr[][n], int m) 
	{
	int i, j;
	
	//loops through and prints each element in arr
	for(i = 0; i < m; i++) 
		for(j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
	
	//narr is a pointe to a pointer -- allocates
	//memory to point to m int* (int pointers)
	int **narr = (int**) malloc(m * sizeof(int*));
	
	//for each int* m in narr, allocates memory for n ints 
	for(i = 0; i < m; i++)
		narr[i] = (int *) malloc((n) * sizeof(int));
	
	//makes narr an incremented copy of arr where each element 
	//narr[i][j] is arr[i][j] + 1
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			narr[i][j] = arr[i][j] + 1;
	
	//prints each element in narr
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", narr[i][j]); 
	
	
	return 1;
	
	
	}
	
int main() 
{
	int arr[][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}};
	
	//here sizeof(arr)/sizeof(arr[0]) tells you how many "rows" of two
	//columns are in arr
	return dynamic2dArrayExample(arr, sizeof(arr)/sizeof(arr[0]));
	
	//should print 0 1 2 3 4 5 6 7 1 2 3 4 5 6 7 8
}
