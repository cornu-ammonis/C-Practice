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

//takes two arrays and returns true if there is any overlap between the
//range represented by the first 2 elements of each array
//else returns false (1 and 0 respectively)
int isOverlap(int a[3], int b[3])
{
	return ( (a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]) );
}

int addOrIncrementOverlapRange(int a[3], int b[3], int **arr, int currentPosition)
{
	int toAdd[3] = {max(a[0], b[0]), min(a[1], b[1]), a[2] + b[2]};
	int i;
	int toReturn = 0;
	for(i = 0; i < currentPosition; i++) 
	{
		if (arr[i][0] == toAdd[0] && arr[i][1] == toAdd[1])
		{
			arr[i]
		}
	}
}

int computeRangeOverlap( int arr[][n], int m) 
	{
	
	//narr[x][0] and narr[x][1] will be the original range from arr,
	//narr[x][2] will be the "counter" for the number of times that range
	//has appeared
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
				
			//TO DO - implement condition where there is incomplete overlap between two ranges,
			//add new shrunken range with +1 to increment position
			//create a helper function which either adds new range, 
			//or increments existing one if it already exists 
			else if (isOverlap(narr[range], narr[j])) 
			{
				if(currentPosition < currentMax)
				{
					addOrIncrementOverlapRange(narr[range], narr[j], currentPosition);
					currentPosition++;
				}
				else 
				{
					narr = resizeAndCopy(narr, currentMax);
					currentPosition = currentMax; //this should already be true
					currentMax *= 2;
					addOrIncrementOverlapRange(narr[range], narr[j], currentPosition);
					currentPosition++;
					
				}
			}
			
			}
		}
	
	
	
	return 1;
	
	
	}
	
int main() 
{
	int arr2[][3] = {{0, 3, 0}, {-5, 2, 0}, {1, 2, 0}, {0, 1, 0}, {7, 8, 0}};
	int arr[][2] = {{0, 1}, {2,3}, {4,5}, {6,7}};
	//return computeRangeOverlap(arr, sizeof(arr)/sizeof(arr[0]));
	
	int **tarr;
	tarr = convertToPointer(arr, sizeof(arr)/sizeof(arr[0]));
	tarr = resizeAndCopy(tarr, sizeof(arr)/sizeof(arr[0]));
	int i,j;
	for(i = 0; i < (sizeof(arr)/sizeof(arr[0])) * 2; i++)
		for(j = 0; j < 3; j++)
			printf("%d ", tarr[i][j]);
	
	printf("\n %d ", isOverlap(arr2[1], arr2[2]));
	printf("\n %d ", isOverlap(arr2[2], arr2[1]));
	printf("\n %d ", isOverlap(arr2[2], arr2[3]));
	printf("\n %d ", isOverlap(arr2[3], arr2[2]));
	printf("\n %d ", isOverlap(arr2[3], arr2[4]));
	printf("\n %d ", isOverlap(tarr[1], tarr[2]));
	printf("\n %d ", isOverlap(tarr[1], arr2[2]));
	return 1;
	
}
