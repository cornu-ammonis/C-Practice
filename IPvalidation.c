#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* validIPAddress(char* IP) 
{
	int len = strlen(IP); //length of input string
	
	if(len == 0)
		return "Neither";
	
	int i;
	int dotCount = 0; //counts periods in string
	int colonCount = 0; //counts colons in string
	
	for(i = 0; i < len; i++)
	{
		if (IP[i] == '.')
			dotCount++;
		else if (IP[i] == ':')
			colonCount++;
	}
	
	//there must be exactly 3 periods xor 7 colons, and only one may be greater
	//than 0, else return Neither as it is not a valid IP
	if(!((dotCount == 3 ^ colonCount == 7) && (dotCount > 0 ^ colonCount > 0)))
		return "Neither";
	
	
	return len;
    
}

int main(void) 
{
	printf("Returned Length is %d ", validIPAddress("abcdefg"));
	return 1;
}
