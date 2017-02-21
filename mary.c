#include <stdio.h>
#include <stdlib.h>

int mary(int N, int K) {
	int *array = malloc(N * sizeof(int));
	array[0] = 0;
	
	int n;
	for(n = 1; n < N; n++) {
		array[n] = (array[n-1] + K)%(n+1);
		
	}
	
	int r = array[N-1];
	free(array);
	return r + 1;
}

int main()
{
	int N;
	int K;
	
	printf("enter a number for N\n");
	
	char line[20];
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &N);
	
	
	printf("Enter a number for K\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &K);
	
	printf("You entered %d for N and %d for K \n", N, K);
	
	
	int ans = mary(N, K);
	printf("The answer is position %d \n", ans);
	return 0;
}



