////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 15:11:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1732KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int n,*m;
	while(cin>>n){
	m=new int[n];
	for(int i=0;i<n;i++)
		cin>>m[i];
	sort(m,m+n);
	cout<<m[n/2]<<endl;
	delete []m;}
	return 0;
}