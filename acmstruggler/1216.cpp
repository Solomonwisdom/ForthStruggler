////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 19:59:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1216
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1816KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int lucky[3001],num[50001];
	int i,j,k;
	int count,n;
	memset(num,0,sizeof(num));
	for(i=2,k=1;k<3001;i++){
		if(!num[i]){
			lucky[k++]=i;
			for(j=i+1,count=0;j<50001;j++){
				if(!num[j])
					count++;
				if(count==i){
					num[j]=1;
					count=0;
				}
			}
		}
	}
	while(scanf("%d",&n)!=EOF&&n){
		printf("%d\n",lucky[n]);
	}
	return 0;
}