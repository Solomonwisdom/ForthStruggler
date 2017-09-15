////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 11:11:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1313
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	char shu[62];
	int len,t1[61]={0},t2[61]={0},i,j,r,k,b;
	bool flag;
	while(cin>>shu)
	{
		len=strlen(shu);
		for(i=0;i<len;i++)
			t1[i]=shu[i]-'0';
		for(i=2;i<=len;i++){
		    flag=false;
			for(j=len-1,r=0;j>=0;j--){
				r+=t1[j]*i;
				t2[j]=r%10;
				r/=10;
			}
			for(j=0;j<len;j++){
				if(t2[j]==t1[0]){
					k=j;
					for(b=0;b<len;b++){
						if(t2[k]!=t1[b]) break;
						k==len-1?k=0:k++;
					}
					if(b==len){ flag=true; break;}
				}
			}
			if(!flag) break;
		}
		if(flag) printf("%s is cyclic\n",shu);
		else printf("%s is not cyclic\n",shu);
	}
	return 0;
}