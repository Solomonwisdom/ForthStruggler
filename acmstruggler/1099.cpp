////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-30 09:08:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
	long long r;
	while((r=a%b)!=0){
		a=b;
		b=r;
	}
	return b;
}
int getlen(long long a){
	int len=0;
	while(a){
		a/=10;
		len++;
	}
	return len;
}
int main(char argc,char *argv[])
{
	long long n,i,fz,fm,div;
	while(scanf("%lld",&n)!=EOF){
		fz=0;
		fm=1;
		for(i=1;i<=n;i++){
			fz=fz*i+fm*n;
			fm*=i;
			div=gcd(fz,fm);
			fz/=div;
			fm/=div;
		}
		if(fz%fm==0)
			printf("%d\n",fz/fm);
		else{
			for(i=0;i<getlen(fz/fm)+1;i++)
				printf(" ");
			printf("%d\n",fz%fm);
			printf("%d ",fz/fm);
			for(i=0;i<getlen(fm);i++)
				printf("-");
			printf("\n");
			for(i=0;i<getlen(fz/fm)+1;i++)
				printf(" ");
			printf("%d\n",fm);
		}
	}
	return 0;
}