////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 17:36:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int num,i,j,k;
	bool flag;
	while(cin>>num){
		flag=false;
	for(i=1;i*i<num;i++){
		for(j=i;j*j<num-i*i;j++){
			for(k=j;k*k<=num-i*i-j*j;k++)
				if(i*i+j*j+k*k==num) {
					printf("%d %d %d\n",i,j,k);
					flag=true;break;
				}
				if(flag) break;}
		if(flag) break;}
	}
	return 0;
}