////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-31 17:58:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1006
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct set{
	double l,r;
};
set solve(double a,double b,double d){
	set ans;
	if(a>0){
		ans.l=(d-b)/a;
		ans.r=(360-d-b)/a;
	}
	else{
		ans.l=(360-d-b)/a;
		ans.r=(d-b)/a;
	}
	if(ans.l<0) ans.l=0;
	if(ans.r>60) ans.r=60;
	if(ans.l>ans.r) ans.l=ans.r=0;
	return ans;
}
set merge(set a,set b){
	set ans;
	ans.l=a.l<b.l?b.l:a.l;
	ans.r=a.r>b.r?b.r:a.r;
	if(ans.l>ans.r) ans.l=ans.r=0;
	return ans;
}
int main(char argc,char *argv[])
{
	double d,a1,a2,a3,b1,b2,b3,time;
	set ans[3][2],temp;
	while(scanf("%lf",&d)!=EOF&&d!=-1){
		time=0;
		for(int i=0;i<12;i++)
			for(int j=0;j<60;j++){
				a1=-5.9;b1=6*j;
				a2=1.0/120-6;b2=30*i+0.5*j;
				a3=1.0/120-0.1;b3=30*i-5.5*j;
				ans[0][0]=solve(a1,b1,d);ans[0][1]=solve(-a1,-b1,d);
				ans[1][0]=solve(a2,b2,d);ans[1][1]=solve(-a2,-b2,d);
				ans[2][0]=solve(a3,b3,d);ans[2][1]=solve(-a3,-b3,d);
				for(int k=0;k<2;k++)
					for(int m=0;m<2;m++)
						for(int n=0;n<2;n++){
							temp=merge(merge(ans[0][k],ans[1][m]),ans[2][n]);
							time+=temp.r-temp.l;
						}
			}
			printf("%.3lf\n",time*100/(12*3600));
	}
	return 0;
}