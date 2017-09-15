////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 10:55:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int m,k,day,acu;
	while(scanf("%d %d",&m,&k)!=EOF&&m&&k){
		day=acu=0;
		while(m){
			day++;
			acu++;
			m--;
			if(acu==k){
				m++;
				acu=0;
			}
		}
		printf("%d\n",day);
	}
	return 0;
}/*
 #include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n && (m||n))
	{
		int ans=(m/(n-1))*n;
	    if(m%(n-1))
	        ans+=(m%(n-1));
	    else
	        ans--;
	    cout<<ans<<endl;
	}
}*/