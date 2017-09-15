////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 21:51:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1323
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int per(int n){
	int sumdiv=1;
	for(int i=2;i<sqrt(double(n));i++)
		if(n%i==0) sumdiv+=n/i+i;
	if(sumdiv>n) return 2;
	else if(sumdiv==n) return 1;
	else return 0;
}
int main(void){
	int n[100],i=0,res;
	while(cin>>n[i++]&&n[i-1]);
	i--;
	printf("PERFECTION OUTPUT\n");
	for(int j=0;j<i;j++){
		res=per(n[j]);
		if(res==0) cout<<setw(5)<<n[j]<<"  DEFICIENT"<<endl;
		else if(res==1) cout<<setw(5)<<n[j]<<"  PERFECT"<<endl;
		else cout<<setw(5)<<n[j]<<"  ABUNDANT"<<endl;
	}
	printf("END OF OUTPUT\n");
}