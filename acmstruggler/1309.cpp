////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 10:38:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1309
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
	int mouth,n,num,i,j;
	double back,loan,value,*des,pre;
	while(cin>>mouth>>back>>loan>>n&&mouth>=0){
		value=loan+back;;
		des=new double[mouth+1];
		for(i=0,j=0;i<n;i++){
			cin>>num>>pre;
			if(i==0) des[j++]=pre;
			else{
				while(j<num){
					des[j]=des[j-1];
					j++;
				}
				des[j++]=pre;
			}
		}
		while(j<=mouth){
			des[j]=des[j-1];
			j++;
		}
		value-=value*des[0];
		back=loan/mouth;
		if(value>=loan){
			printf("0 months\n");
			continue;
		}
		for(i=1;i<=mouth;i++){
			value-=value*des[i];
			loan-=back;
			if(value>=loan) break;
		}
		if(i==1) printf("1 month\n");
		else printf("%d months\n",i);
		delete []des;
	}
	return 0;
}