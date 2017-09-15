////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 15:32:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1361
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int t,n,x,i,a,left,leftp;
	char pare[50];
	bool flag,ever[50];
	cin>>t;
	while(t--){
		cin>>n;
		x=0;
		for(i=0;i<50;i++){pare[i]='0'; ever[i]=true;}
		for(i=0;i<n;i++){
			scanf("%d",&a);
			pare[a+x]=')';
			x++;
		}
		flag=true;
		for(i=0;i<2*n;i++)
		{
			left=1;leftp=1;
			if(pare[i]==')'){
				while(ever[i-left]==false||pare[i-left]==')'){
					if(pare[i-left]!=')') leftp++;
					left++;
				}
				ever[i-left]=false;
				if(flag){flag=false; printf("%d",leftp);}
				else printf(" %d",leftp);
			}
		}
		printf("\n");
	}
	return 0;
}