////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 10:48:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int A,B,n,f[50],i;
	f[1]=f[2]=1;
	while((cin>>A>>B>>n)&&(A||B||n))
	{
		if(n==1||n==2){ cout<<f[n]<<endl;continue;}
		for(i=3;i<=49;i++)
	    {
			f[i]=(A*f[i-1]+B*f[i-2])%7;
		    if(f[i]==1&&f[i-1]==1) break;
	    }
	    i-=2;
		n%=i;
		if(n==0) cout<<f[i]<<endl;
		else cout<<f[n]<<endl;
	}
	return 0;
}