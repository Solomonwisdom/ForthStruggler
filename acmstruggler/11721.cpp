////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 17:04:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct guess{
	int b,c,d;
};
int main(void){
	int n,i,j,sum,ji1,ji2,hash1[10],hash2[10];
	int res;
	guess *a;
	char s1[5],s2[5];
	while(scanf("%d",&n)!=EOF&&n){
		a=new guess[n];
		for(i=0;i<n;i++)
			scanf("%d %d %d",&a[i].b,&a[i].c,&a[i].d);
		sum=0;
		for(i=1000;i<10000;i++){
			for(j=0;j<n;j++){
				itoa(i,s1,10);
				itoa(a[j].b,s2,10);
				ji1=ji2=0;
				for(int k=0;k<4;k++)
					if(s1[k]==s2[k])
						ji1++;
				if(ji1==a[j].d){
					memset(hash1,0,sizeof(hash1));
					memset(hash2,0,sizeof(hash2));
					for(int k=0;k<4;k++){
						hash1[s1[k]-'0']++;
						hash2[s2[k]-'0']++;
					}
					for(int k=0;k<10;k++){
						if(hash1[k]<=hash2[k])
							ji2+=hash1[k];
						else ji2+=hash2[k];
					}
					if(ji2!=a[j].c)
						break;
				}
				else break;
			}
			if(j==n){
				sum++;
				res=i;
			}
			if(sum>1){
				printf("Not sure\n");
				break;}
		}
		if(sum==1) printf("%d\n",res);
		delete []a;
	}
	return 0;
}