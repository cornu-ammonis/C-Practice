#include <stdlib.h>
#include <stdio.h>
const int n = 2; //second dimension for range array, eg [0, 1]

//doubles m, keeps n+1 dimensoin, copies current elements
//initializes empty elements to 0
int** resizeAndCopy(int **arr, int m) 
	{
	int i, j;
	int **narr = (int**) malloc((2*m) * sizeof(int*));
	
	for(i = 0; i < (m*2); i++)
		narr[i] = (int *) calloc((n + 1), sizeof(int));
	
	for( i = 0; i < m; i++)
		for( j = 0; j < n+1; j++)
			narr[i][j] = arr[i][j];
	
	return narr;
	}

//takes an int[*][n] array and the size of the first dimension, m,
//and converts it to int** suitable for processing elsewhere in the program
//adds one to n and intializes 2nd place to 1
int** convertToPointer(int arr[][n], int m) 
	{
	int **narr = (int**) malloc(m * sizeof(int*));
	int i,j;
	for(i = 0; i < m; i++)
		narr[i] = (int*) calloc((n+1), sizeof(int));
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++) {
			narr[i][j] = arr[i][j]; }
			
		narr[i][2] = 1;
		}
		
	
	return narr;
	
	}

int computeRangeOverlap( int arr[][n], int m) 
	{
	
	int **narr = convertToPointer(arr, m);
	narr = resizeAndCopy(narr, m);
	
	int currentPosition = m; //inclusive - narr[m] is 'empty' (actually all 0s)
	int currentMax = 2*m; //not inclusive - while i < currentMax
	
	int range; // which range in input element we are processing
	int j; //iterator for dp structure
	int incrementedDuplicate;
	for (range = 0; range < m; range++) 
		{
		incrementedDuplicate = 0;
		
		//loop through all ranges ahead of our current range
		for(j = range + 1; j < currentMax; j++) 
			{
				
			//if they are the same range and we havent met another copy
			//of same range, increment count and continue
			if(narr[range][0] == narr[j][0] && narr[range][1] == narr[j][1] && !incrementedDuplicate) 
				{
				narr[j][2] = narr[j][2] + narr[range][2];
				incrementedDuplicate = 1;
				continue; 
				}
			
			}
		}
	
	
	
	return 1;
	
	
	}
	
int main() 
{
	//int arr[][2] = {{0, 3}, {-5, 2}, {1, 2}, {0, 1}};
	int arr[][2] = {{0, 1}, {2,3}, {4,5}, {6,7}};
	//return computeRangeOverlap(arr, sizeof(arr)/sizeof(arr[0]));
	
	int **tarr;
	tarr = convertToPointer(arr, sizeof(arr)/sizeof(arr[0]));
	tarr = resizeAndCopy(tarr, sizeof(arr)/sizeof(arr[0]));
	int i,j;
	for(i = 0; i < (sizeof(arr)/sizeof(arr[0])) * 2; i++)
		for(j = 0; j < 3; j++)
			printf("%d ", tarr[i][j]);
			
	return 1;
	
}
