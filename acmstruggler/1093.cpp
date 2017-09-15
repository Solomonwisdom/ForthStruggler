////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:07:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
    int a,n,m;
	int sum;
	cin>>m;
	while(m--){
		cin>>n;
		sum=0;
		while(n--){
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
	}
    return 0;
}