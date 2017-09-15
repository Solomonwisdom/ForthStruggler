////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 12:01:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
struct stu{
	string num,s1,s2;
};
int main(void){
	int early,late,n,m;
	string ss1,ss2;
	stu *st;
	while(cin>>n)
	{
		while(n--){
		cin>>m;
		st = new stu[m];
		for(int i=0;i<m;i++)
		{
			cin>>st[i].num>>st[i].s1>>st[i].s2;
			if(i==0){ ss1=st[i].s1;early=0;}
			else if(ss1>st[i].s1) { ss1=st[i].s1;early=i;}
			if(i==0){ ss2=st[i].s2;late=0;}
			else if(ss2<st[i].s2) { ss2=st[i].s2;late=i;}
		}
		cout<<st[early].num<<' '<<st[late].num<<endl;
		delete []st;
		}
	}
	return 0;
}