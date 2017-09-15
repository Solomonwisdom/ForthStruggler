////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-03 09:32:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2364KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct tage{
	int j,f;
	double jf;
};
bool cmp(tage s,tage t){
	if(s.jf==t.jf)
		return s.f<t.f;
	return s.jf<t.jf;
}
int main(char argc,char *argv[])
{
	tage *t;
	int m,n;
	double sum;
	while(scanf("%d %d",&m,&n)!=EOF&&m!=-1&&n!=-1){
		t=new tage[n];
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d %d",&t[i].j,&t[i].f);
			t[i].jf=double(t[i].f)/t[i].j;
		}
		sort(t,t+n,cmp);
		for(int i=0;i<n;i++){
			if(m>=t[i].f){
				sum+=t[i].j;
				m-=t[i].f;
			}
			else{
				sum+=double(m)/t[i].f*t[i].j;
				break;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}