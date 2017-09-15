////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 20:35:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1302
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int h,u,d,count;
	double f,sum;
	bool flag;
	while(cin>>h>>u>>d>>f&&h){
		f/=100;
		flag=false;
		count=1;
		sum=0;
		while(cout){
			sum+=u-(count-1)*u*f;
			if(sum>h){ flag=true;break;}
			sum-=d;
			if(sum<0) break;
			count++;
		}
		if(flag) printf("success on day %d\n",count);
		else printf("failure on day %d\n",count);
	}
	return 0;
}