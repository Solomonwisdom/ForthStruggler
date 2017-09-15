////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 16:39:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
	if(n==1) return false;
	if(n==2) return true;
	bool flag=true;
	for(int i=2;i<=sqrt(double(n));i++)
		if(n%i==0){ flag=false;break;}
	return flag;
}
int main(void){
	int n,x,k;
	while(cin>>n){
		x=n/2;
		for(k=x;k<n;k++)
			if(prime(k)&&prime(n-k)) break;
		printf("%d %d\n",n-k,k);
	}
	return 0;
}