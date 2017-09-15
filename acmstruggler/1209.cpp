////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 18:23:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1209
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct angle{
	double a;
	int h,m;
	int time;
};
bool cmp(angle a1,angle a2){
	if(a1.a==a2.a)
		return a1.time<a2.time;
	else 
		return a1.a<a2.a;
}
int main(void){
	int n,h,m;
	angle an[5];
	double ha,ma,aa;
	scanf("%d",&n);
	while(n--){
		for(int i=0;i<5;i++){
			scanf("%d:%d",&h,&m);
			an[i].h=h;
			an[i].m=m;
			an[i].time=h*60+m;
			ha=h%12*30+m*0.5;
			ma=m*6;
			aa=abs(ha-ma);
			if(aa>180) aa=360-aa;
			an[i].a=aa;
		}
		sort(an,an+5,cmp);
		printf("%02d:%02d\n",an[2].h,an[2].m);
	}
	return 0;
}