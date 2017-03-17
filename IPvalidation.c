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
	
	if(dotCount > 0)
		return IPv4(IP, len, 0);
	else
		return IPv6(IP);
	
	return "Neither";
    
}
int IPv4(char* ip, int len, int start){
	return 1;}
	
int IPv6(char* ip, int len, int start){
	return 1;}

char* IPv5(char* ip, int len, int start) 
{
	
	if(len == start)
		return 1; //base case
	if (ip[start] == '.')
		start++;
		
	int i = start;
	while(i < len && ip[i] != '.')
		i++;
	
	int n = i - start;
	char* sub = (char*) malloc(sizeof(char)*n+1);
	int j = 0;
	int k;
	
	for(k = start; k < i; k++)
	{
		sub[j++] = ip[k];
	}
	sub[n] = '\0';
	return sub;
	
	
}

int main(void) 
{
	char* test = "11.12.1.11.1";
	printf(IPv5(test, strlen(test), 0));
	return 1;
}
