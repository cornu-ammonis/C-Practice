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

int** addOverlapRange(int a[3], int b[3], int **arr, int currentPosition)
{
	int toAdd[3] = {MAX(a[0], b[0]), MIN(a[1], b[1]), a[2] + b[2]};
	arr[currentPosition]= toAdd;
	return arr;
}

int computeRangeOverlap( int arr[][n], int m) 
	{
	
	//narr[x][0] and narr[x][1] will be a range, narr[x][2] will be
	// the "counter" for the number of times that range has appeared
	int **dp = (int**) malloc(m * 2 * sizeof(int*));
	int i;
	for(i = 0; i < m*2; i++)
		dp[i] = calloc(3, sizeof(int));
	
	//pointer to current first available element in dp
	int dpi = 0; //inclusive - narr[m] is 'empty' (actually all 0s)
	int currentMax = 2*m; //not inclusive - while i < currentMax
	int alreadyAdded; //tracks whether alrady added range from parameter
	int range; // which range in input element we are processing
	
	
	for (range = 0; range < m; range++) 
	{
		alreadyAdded = 0;
		int toAdd[3] = {arr[range][0], arr[range][1], 1};
		int loopCeiling = dpi; //distinct from dpi because dpi may increment in loop
		for(i = 0; i < loopCeiling; i++) 
		{
			//if this exact range is already in dp
			if(dp[i][0] == arr[range][0] && dp[i][1] == arr[range][1])
			{
				dp[i][2] += 1; //increment the count
				alreadyAdded = 1; //mark we've already added this range
				continue;
			}
			
			else
			{
				if(isOverlap(dp[i], toAdd))
				{
					
				//resizes dynamic programming structure if needed
					if ( dpi >= currentMax)
					{
						dp = resizeAndCopy(dp, currentMax);
						currentMax *= 2;
					}
				
					dp = addOverlapRange(dp[i], toAdd, dp, dpi);
					dpi++;
				} 
			}
		}
		if(!alreadyAdded) 
		{
			if (dpi >= currentMax)
			{
				dp = resizeAndCopy(dp, currentMax);
				currentMax *= 2;
			}
			
			dp[dpi++] = toAdd;
		}
		
	}
	
	int currentAns = dp[0][0];
	int currentMaxCount = dp[0][2];
	for (i = 0; i < dpi; i++)
	{
		if(dp[i][2] > currentMaxCount) 
		{
			currentMaxCount = dp[i][2];
			currentAns = dp[i][0];
		}
	}
	return currentAns;
	
	
	}
	
int main() 
{
	//int arr2[][3] = {{0, 3, 0}, {-5, 2, 0}, {1, 2, 0}, {0, 1, 0}, {7, 8, 0}};
	int arr[][2] = {{0, 1}, {2,3}, {4,5}, {6,7}};
	/*//return computeRangeOverlap(arr, sizeof(arr)/sizeof(arr[0]));
	
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
	printf("\n %d ", isOverlap(tarr[1], arr2[2]));*/
	int ans = computeRangeOverlap(arr, sizeof(arr)/sizeof(arr[0]));
	printf("a max overlap number is: %d", ans);
	return 1;
	
}
