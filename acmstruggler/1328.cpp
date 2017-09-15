////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 09:54:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1328
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
    int n;
	char str[51];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>str;
		for(int j=0;str[j]!='\0';j++){
			str[j]++;
			if(str[j]>'Z') str[j]-=26;
		}
		printf("String #%d\n%s\n\n",i,str);
	}
    return 0;
}