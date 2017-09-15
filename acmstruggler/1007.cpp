////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-31 19:11:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:2090MS
////Run memory:4760KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
};
double dis(point a,point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
bool cmp(point a,point b){
	if(a.x!=b.x) 
		return a.x<b.x;
	return a.y<b.y;
}
bool cmpy(point a,point b){
	return a.y<b.y;
}
point *toy,*fac;
double closest(int low,int high){
	if(high-low==1)
		return dis(toy[low],toy[high]);
	double d=1e20;
	if(low==high) return d;
	int middle=(low+high)/2;
	double dl=closest(low,middle);
	double dr=closest(middle+1,high);
	d=dl<dr?dl:dr;
	int num=0;
	for(int i=low;i<=high;i++){
		if(fabs(toy[i].x-toy[middle].x)<=d)
			fac[num++]=toy[i];
	}
	sort(fac,fac+num,cmpy);
	for(int i=0;i<num-1;i++)
		for(int j=i+1;j<num&&fac[j].y-fac[i].y<d;j++)
			d=d<=dis(fac[i],fac[j])?d:dis(fac[i],fac[j]);
	return d;
}
int main(char argc,char *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		toy=new point[n];
		fac=new point[n];
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&toy[i].x,&toy[i].y);
		sort(toy,toy+n,cmp);
		double min=closest(0,n-1);
		printf("%.2lf\n",min/2);
		delete []toy;
		delete []fac;
	}
	return 0;
}