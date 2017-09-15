////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 16:48:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int N,n,m,i,j,k,count,times;
	cin>>N;
	for(i=1;i<=N;i++)
	{
		times=1;
		while(cin>>n>>m && (n||m)){
			count=0;
			for(j=1;j<n;j++)
				for(k=j+1;k<n;k++)
					if((j*j+k*k+m)%(j*k)==0) count++;
			cout<<"Case "<<times<<": "<<count<<endl;
			times++;
		}
		if(i!=N) cout<<endl;
	}
	return 0;
}