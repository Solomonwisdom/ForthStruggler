////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 15:31:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int t,a,b;
	char op;
	scanf("%d",&t);
	while(t--){
		getchar();
		scanf("%c %d %d",&op,&a,&b);
		if(op=='+') printf("%d\n",a+b);
		else if(op=='-') printf("%d\n",a-b);
		else if(op=='*') printf("%d\n",a*b);
		else if(op=='/')
			if(a%b) printf("%.2f\n",double(a)/b);
			else printf("%d\n",a/b);
	}
	return 0;
}