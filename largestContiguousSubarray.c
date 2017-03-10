#include<stdio.h>
#include<stdlib.h>

//returns the sum of the largest contiguous subarray in nums
int maxSubArray(int* nums, int numsSize) 
	{
		
		int currentMax = nums[0];
		int tmpMax = nums[0];
		int i;
		for(i = 0; i < numsSize; i++) 
			{
				tmpMax += nums[i];
				if (tmpMax > currentMax)
					currentMax = tmpMax;
				else if (tmpMax < 0)
					tmpMax = 0;
					
			}
		return currentMax;
		
	}

int main()
{
	int testarr[] = {-1};
	int n = sizeof(testarr)/sizeof(testarr[0]);
	int ans = maxSubArray(testarr, n);
	printf("testarr answer is %d \n", ans);
	return 1;
}