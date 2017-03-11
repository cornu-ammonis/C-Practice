#include <stdlib.h>
#include <stdio.h>
const int n = 2; //second dimension for range array, eg [0, 1]

//doubles m, keeps the same n, copies current elements
//initializes empty elements to 0
int** resizeAndCopy(int **arr, int m, int n) 
	{
	int i, j;
	int **narr = (int**) malloc((2*m) * sizeof(int*));
	
	for(i = 0; i < (m*2); i++)
		narr[i] = (int *) calloc(n, sizeof(int));
	
	for( i = 0; i < m; i++)
		for( j = 0; j < n; j++)
			narr[i][j] = arr[i][j];
	
	return narr;
	}

int computeRangeOverlap( int arr[][n], int m) 
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
	
	narr = resizeAndCopy(narr, m, n);
	for(i = m; i < 2*m; i++)
		for(j = 0; j < n; j++)
			narr[i][j] = narr[i-1][j] + 2;
	for (i = 0; i < 2*m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", narr[i][j]); 
	
	
	return 1;
	
	
	}
	
int main() 
{
	//int arr[][2] = {{0, 3}, {-5, 2}, {1, 2}, {0, 1}};
	int arr[][2] = {{0, 1}, {2,3}, {4,5}, {6,7}};
	return computeRangeOverlap(arr, sizeof(arr)/sizeof(arr[0]));
	
	
	
}
