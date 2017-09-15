////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:28:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
bool is(int n){
	if(n==1) return false;
	int sum=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) sum+=i+n/i;
	}
	if(sum==n) return true;
	return false;
}
int main(void)
{
    int n1,n2,n,c;
	scanf("%d",&n);
	while(n--){
		c=0;
		scanf("%d %d",&n1,&n2);
		if(n1>n2){
			int temp=n1;
			n1=n2;
			n2=temp;
		}
		for(int i=n1;i<=n2;i++){
			if(is(i)) c++;
		}
		printf("%d\n",c);
	}
    return 0;
}