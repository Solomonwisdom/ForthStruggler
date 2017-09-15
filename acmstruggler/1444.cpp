////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 20:55:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1444
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    char b[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	char c[10];
	int t,d,y,i,res;
	cin>>t;
	cout<<t<<endl;
	while(t--){
		scanf("%d. %s %d",&d,c,&y);
		for(i=0;i<19;i++)
			if(strcmp(a[i],c)==0) break;
		res=365*y+20*i+d;
		y=res/260;
		i=res%20;
		d=res%13;
		printf("%d %s %d\n",d+1,b[i],y);
	}
	return 0;
}