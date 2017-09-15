////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 11:38:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1338
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2952KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(void)
{
	int m,n,*arr,*card,count=0,win,top;
	while(cin>>m>>n&&m&&n){
		count++;
		arr=new int[n*m];
		for(int i=0;i<n*m;i++) arr[i]=i+1;
		card=new int[n];
		for(int i=0;i<n;i++){
			cin>>card[i];
			arr[card[i]-1]=0;}
		qsort(&card[0],n,sizeof(card[0]),cmp);
		top=n*m-1;
		win=0;
		for(int i=n-1;i>=0;i--){
			while(arr[top]==0) top--;
			if(card[i]>arr[top])
				win++;
			else top--;
		}
		printf("Case %d: %d\n",count,win);
	}
	return 0;
}