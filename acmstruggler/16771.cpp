////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 15:39:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1677
////Problem Title: 
////Run result: Accept
////Run time:889MS
////Run memory:1784KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<algorithm>
using namespace std;
struct doll{
	int hi,wi;
};
int cmp(const void* elem1,const void*elem2){  
    doll *p,*q;  
    p=(doll *)elem1; q=(doll *)elem2;  
    if((p->hi)!=(q->hi))  
        return (p->hi)-(q->hi);  
    else return (q->wi)-(p->wi);   
} 
int main(void)
{
	int t,m,w,h,con,max;
	doll *d;
	bool *full;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&m);
		d=new doll[m];
		con=0;
		full=new bool[m];
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&w,&h);
			d[i].wi=w;
			d[i].hi=h;
			full[i]=false;
		}
		qsort(d,m,sizeof(doll),cmp);
		for(int i=0;i<m;i++)
		{
			if(full[i]) continue;
			con++;
			max=d[i].wi;
			full[i]=true;
			for(int j=i+1;j<m;j++){
				if(full[j]==false&&d[j].wi>max)
				{
					full[j]=true;
					max=d[j].wi;
				}
			}
		}
		printf("%d\n",con);
		delete []d;
		delete []full;
	}
	return 0;
}