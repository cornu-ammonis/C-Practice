#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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

//recursively determines whether the given ip is valid
// @param ip - character array of length 
// @param len - length of ip
// @param start - starting index to parse char array - so that recursive
// calls do not need to rebuild the string
int IPv4(char* ip, int len, int start) 
{
	//if we have gotten to the end of the string
	if(len == start)
		return 1; //base case
	
	//skips a leading period
	if (ip[start] == '.')
		start++;
	
	//loops until we reach a period or the end of string -- 
	//to find the end of the numbers segment to parse
	int i = start;
	while(i < len && ip[i] != '.')
		i++;
	
	//n represents the length of our target substring
	int n = i - start;
	char* sub = (char*) malloc(sizeof(char)*n+1);
	int j = 0; // indexer for substring 
	int k; //indexer for substring within original string

	//builds substring
	for(k = start; k < i; k++)
	{
		sub[j++] = ip[k];
	}
	sub[n] = '\0'; //null terminates
	
	//leading zero is a special case - must be followed by 
	//end of string or a . to be valid
	if(sub[0] == '0')
	{
		if(n > 1 && sub[1] != '.')
			return 0;
		else
			return IPv4(ip, len, i);
	}
	
	//pointer into which parse int will place the integer which the 
	//substring represents
	int* subInt = malloc(sizeof(int));
	
	//ParseInt returns 0 if could not parse an integer from given string
	if(!ParseInt(sub, subInt))
	{
		printf("Something went wrong! exiting..");
		return 0;
	}
	
	//integer must be in range [0,255]
	if(*subInt < 0 || *subInt > 255)
		return 0;
	return IPv4(ip, len, i); //recursive call for next substring 
	
	
	
}

int IPv6(char* ip, int len, int start)
{
printf("madeit\n");
	if(len == start) //base case
		return 1;
	if(ip[start] == ':') //handles leading :
		start++;
	
	int i = start;
	while(i < len && ip[i] != ':')
		i++;
	
	int n = i - start;
	
	char* sub = (char*) malloc(sizeof(char) * n+1);
	int j = 0; // indexer for substring 
	int k; //indexer for substring within original string
	
	//builds substring
	for(k = start; k < i - 1; k++)
	{
		//returns 0 if any part of the substring is not a valid 
		//hex character
		if(isxdigit(ip[k]) == 0)
			return 0;
		sub[j++] = ip[k];
	}

	sub[n] = '\0'; //null terminates
	printf("madeit\n");

	return 1;

}

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
		else if (IP[i] == '-')
			return "Neither";
	}
	
	//there must be exactly 3 periods xor 7 colons, and only one may be greater
	//than 0, else return Neither as it is not a valid IP
	if(!(((dotCount == 3) ^ (colonCount == 7)) && ((dotCount > 0) ^ (colonCount > 0))))
		return "Neither";
	
	if(dotCount > 0)
	{
		if (IPv4(IP, len, 0))
			return "IPv4";
		else
			return "Neither";
	}
		
	else
	{
		if (IPv6(IP, len, 0))
			return "IPv6";
		else
			return "Neither";
	}
	
	return "Neither";
    
}



	




int main(void) 
{
	
	printf("assigning character");
	char* test1 = "85y3";
	printf("calling IPv6");
	int len = strlen(test1);
	int ans = IPv6(test1, len, 0);
	if(ans == 1)
		printf("it worked!");
	else
		printf("no!");
	return 1;
	
}


