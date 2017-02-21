#include <stdlib.h>
#include <stdio.h>

int coinChange(int* coins, int coinsSize, int amount) { 
	if(coinsSize == 0) {
		return -1;
		}
	if(amount == 0){
		return 0;
		}
	
	//used to store answers for all values between 0 and the amount
	int* map = calloc((amount+2), sizeof(int));
	
	map[0] = 0;
	int i; // index for outer loop, i.e. subamount
	int c; //index for inner loop, i.e. which coin
	int temp;//placholder for subamount
	int coin;
	
	//loop up to and including amount
	for(i = 1; i <= amount; i++) {
		temp = i; //temp is our subamount and also our min placeholder;
		//the largest possible number of coins required to produce an 
		//amount is that amount assuming all coins > 1
		
		map[i] = -1; //if no coins can produce this amount make it -1 for future loops
		
		//loop through all possible coins
		for(c = 0; c < coinsSize; c++) {
			coin = coins[c]; //assigns the coin its own value for readability
			
			//if a coin equals an amount, it takes one coin to make that 
			//amount which is smallest possible answer
			if(coin == i) {
				map[i] = 1;
				break; //terminate inner loop
				}
			
			//if a coin is smaller than the sub amount, it is a valid coin
			else if(coin < i) {
				
				//if subamount - coin = -1, we cannot produce that number 
				//with our given coins so must check > -1
				if(map[i - coin] > -1) {
					//takes a previous combo of coins and adds this coin to it to produce a new number of coins
					if((map[i - coin] + 1) <= temp) {
						temp = map[i - coin] + 1;
						map[i] = temp;
						} 
					} 
					
				
				}
			}
		}
	return map[amount];
}

int main() {
		int a = 6249;
		int* c = malloc( 4 * sizeof(int));
		c[0] = 186;
		c[1] = 419;
		c[2] = 83;
		c[3] = 408;
		
		int r = coinChange(c, 4, a);
		printf("the answer produced was %d", r);
		return 0;
	
	}
