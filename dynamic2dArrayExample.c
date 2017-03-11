#include <stdlib.h>
#include <stdio.h>
const int n = 2; //second dimension for range array, eg [0, 1]

int dynamic2dArrayExample( int arr[][n], int m) 
	{
	int i, j;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
	
	int **narr = (int**) malloc(m * sizeof(int*));
	for(i = 0; i < m; i++)
		narr[i] = (int *) malloc((n) * sizeof(int));
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			narr[i][j] = arr[i][j] + 1;
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", narr[i][j]); 
	
	
	return 1;
	
	
	}
	
int main() 
{
	int arr[][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}};
	return dynamic2dArrayExample(arr, sizeof(arr)/sizeof(arr[0]));
	
}
