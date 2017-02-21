#include <stdlib.h>
#include <stdio.h>

int min(int a, int b) {
	if(a < b) {
		return a;
		}
	else {
		return b;
	}
	}

int coinChange(int* coins, int coinsSize, int amount) { 
	if(coinsSize == 0) {
		return -1;
		}
	if(amount == 0){
		return 0;
		}
	
	int* map = calloc((amount+2), sizeof(int));
	
	map[0] = 0;
	int i;
	int c;
	for(i = 1; i <= amount; i++) {
		for(c = 0; c < coinsSize; c++) {
			if(coins[c] == i) {
				map[i] = 1;
				}
				
			else if(coins[c] < i) {
				int remain = i % coins[c];
				if(remain == 0) {
					if(map[i] <= 0) {
						map[i] = (int)i / coins[c];
						}
					else {
						map[i] = min(map[i], (int)i/coins[c]);
						}
					}
				else {
					if(map[remain] <= 0) {
						map[i] = -1;
						}
					else {
						if(map[i] <= 0) {
							map[i] = ((int)i/coins[c]) + map[remain];
							}
						else {
							map[i] = min(map[i], ((int)i/coins[c]) + map[remain]);
							}
						}
					
					}
					
				
				}
			}
		}
	return map[amount];
}

int main() {
		int a = 7;
		int* c = malloc( 3 * sizeof(int));
		c[0] = 3;
		c[1] = 9;
		c[2] = 5;
		
		int r = coinChange(c, 3, a);
		printf("the answer produced was %d", r);
		return 0;
	
	}
