////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 10:42:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1036
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	char times[10];
	int n,num,sum;
	double d,ave;
	bool qua;
	cin>>n>>d;
	while(cin>>num)
	{
		qua=true;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>times;
			if(times[0]=='-') qua=false;
			else {
				sum+=(times[0]-'0')*3600;
				sum+=(times[2]-'0')*600;
				sum+=(times[3]-'0')*60;
				sum+=(times[5]-'0')*10;
				sum+=times[6]-'0';
			}
		}
		ave=sum/d;
		sum=ave+0.5;
		if(qua) printf("%3d:%2d:%02d min/km\n",num,sum/60,sum%60);
		else printf("%3d: -\n",num);
	}
	return 0;
}