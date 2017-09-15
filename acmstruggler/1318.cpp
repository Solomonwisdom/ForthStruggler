////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 17:03:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1318
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAXN 1024
char const *ch = "AEHIJLMOSTUVWXYZ12358";
char const *re = "A3HILJMO2TUVWXY51SEZ8";

int is_palindrome(char *str)
{
	int i,len = strlen(str);
	for(i=0; i<len/2; i++)
	{
		if(str[i] != str[len-i-1])
			return 0;
	}
	return 1;
}

int is_mirrored(char *str)
{
	int table_len = strlen(ch);
	int i,j,len = strlen(str);
	if(len == 1)
	{
		for(j=0; j<table_len; j++)
		{
			if(ch[j] == str[0])
				break;
		}
		if(j == 21 || re[j] != str[0])
			return 0;
	}
	else if(len > 1)
	for(i=0; i<len/2; i++)
	{
		for(j=0; j<table_len; j++)
		{
			if(ch[j] == str[i])
				break;
		}	
		if(j == 21 || re[j] != str[len-i-1])
			return 0;
	}
	return 1;
}


int main()
{
	//freopen("C:\\in.txt","r",stdin);
	char str[MAXN];	
	while(scanf("%s",str) != EOF)
	{
		if(is_palindrome(str))
		{
			if(is_mirrored(str))
				printf("%s -- is a mirrored palindrome.\n\n",str);
			else
				printf("%s -- is a regular palindrome.\n\n",str);
		}
		else
		{
			if(is_mirrored(str))
				printf("%s -- is a mirrored string.\n\n",str);
			else
				printf("%s -- is not a palindrome.\n\n",str);
		}
	}
	return 0;
}