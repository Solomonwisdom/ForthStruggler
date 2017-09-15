////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 19:22:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,m;
	bool flag;
	cin>>n;
	while(n--){
		cin>>m;
		flag=true;
		if((m&(m-1))==0){ printf("No number can be output !\n");continue;}
		while(m!=1){
			if(m%2==0) m/=2;
			else { if(!flag) printf(" ");
			else flag=false;
			printf("%d",m);m=3*m+1;
			}	
		}
		printf("\n");
	}
	return 0;
}