#include<stdio.h>
#include<stdlib.h>

//returns the sum of the largest contiguous subarray in nums
int maxSubArray(int* nums, int numsSize) 
	{
		
		int currentMax = nums[0];
		int tmpMax = nums[0];
		int i;
		int hasPositive = 0; //tracks whether there are only negative members
		for(i = 0; i < numsSize; i++)
			{
				if (nums[i] > 0) {
					hasPositive = 1;
					break;}
			}
		for(i = 1; i < numsSize; i++) 
			{
				tmpMax += nums[i];
				if (tmpMax > currentMax)
					currentMax = tmpMax;
				else if (tmpMax < 0 && hasPositive)
					tmpMax = 0;
				
				// handles case with all negative numbers
				else if (!hasPositive){
					if (nums[i] > currentMax) 
						currentMax = nums[i];
					}
					
			}
		return currentMax;
		
	}

int main()
{
	int testarr[] = {1};
	int n = sizeof(testarr)/sizeof(testarr[0]);
	int ans = maxSubArray(testarr, n);
	printf("testarr answer is %d \n", ans);
	return 1;
}
