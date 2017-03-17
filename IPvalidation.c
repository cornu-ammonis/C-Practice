#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int ParseInt(const char *s,int *i)
{
    char *ep;
    long l;

    l=strtol(s,&ep,0);

    if(*ep!=0)
        return 0;

    *i=(int)l;
    return 1;
 }

int IPv4(char* ip, int len, int start) 
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
	
	int* subInt = malloc(sizeof(int));
	
	if(!ParseInt(sub, subInt))
	{
		printf("Something went wrong! exiting..");
		return 0;
	}
	
	if(*subInt < 0 || *subInt > 255)
		return 0;
	return IPv4(ip, len, i);
	
	
	
}

int IPv6(char* ip, int len, int start){
	return 1;}

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
	if(!(((dotCount == 3) ^ (colonCount == 7)) && ((dotCount > 0) ^ (colonCount > 0))))
		return "Neither";
	
	if(dotCount > 0)
		return IPv4(IP, len, 0);
	else
		return IPv6(IP, len, 0);
	
	return "Neither";
    
}



	




int main(void) 
{
	char* test = "255.255.255.255.255";
	if(IPv4(test, strlen(test), 0))
		printf("valid!");
	else
		printf("Invalid or error!");
	return 1;
}


