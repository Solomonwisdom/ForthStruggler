////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-23 20:23:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(int a[],int b[]){
	return a[1]<a[1];
}
int main(void)
{
    int T,n,room[200],i,max,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(room,0,sizeof(room));
		max=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&s,&t);
			s=(s-1)/2;
			t=(t-1)/2;
			if(s>t){
				s=s^t;
				t=s^t;
				s=s^t;
			}
			for(int j=s;j<=t;j++){
				room[j]++;
				max=max>room[j]?max:room[j];
			}
		}
		printf("%d\n",10*max);
	}
    return 0;
}