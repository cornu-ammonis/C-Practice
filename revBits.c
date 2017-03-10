#include<stdio.h>
#include<stdlib.h>

unsigned int rev (int i, int j, unsigned int A) {
	
	unsigned int lo = (A >> i) & 1;
	unsigned int hi = (A >> j) & 1;
	unsigned int one = 1;
	if (lo ^ hi) 
		A ^= (one << i) | (one << j);
	
	return A;
	
	}
unsigned int revBits(unsigned int A) {
	
	int n = sizeof(A) * 8;
	
	int i;
	for(i = 0; i < n/2; i ++)
		A = rev(i, n - i - 1, A);
	
	return A;
}

int main() {
	
	unsigned int a = 3;
	printf("for 1 we get: %u", revBits(a));
	return 1;
}
