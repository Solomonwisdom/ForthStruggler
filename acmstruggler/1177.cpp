////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 17:35:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1177
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct li
{
	int count;
	int h;
	int m;
	int s;
	int num;
}q[150];

int cmp( const void *a , const void *b )
{ 
	struct li *c = (li *)a;
	struct li *d = (li *)b; 
	if(c->count != d-> count) 
		return d->count - c->count; 
	else	
	{
		if(c->h != d->h) 
			return c->h - d->h;
		else	
		{
	    	if(c->m != d->m) 
	    		return c->m - d->m;
	        else	
	    		return c->s - d->s;
		}
	}
} 

int main()
{
	int n,j,y,t,m,i;
	while(cin>>n>>j>>y>>t>>m,(n||j||y||t||m))
	{
        for(i=0;i<n;i++)
		{
			scanf("%d %d:%d:%d",&q[i].count,&q[i].h,&q[i].m,&q[i].s);
            if(i!=m-1)
				q[i].num=0;
			else
				q[i].num=1;
		}
		qsort(q,n,sizeof(q[0]),cmp);
		for(i=0;i<n;i++)
		{
			if(q[i].num==1)
			{
				if(i+1<=j)
					cout<<"Accepted today? I've got a golden medal :)"<<endl;
				else
					if(i+1<=j+y)
						cout<<"Accepted today? I've got a silver medal :)"<<endl;
					else
						if(i+1<=j+y+t)
                            cout<<"Accepted today? I've got a copper medal :)"<<endl;
						else
							cout<<"Accepted today? I've got an honor mentioned :)"<<endl;
			    break;
			}
		}
	}
	return 0;
}/*#include<iostream>
#include<algorithm>
using namespace std;
struct sone{
	int id,time,num;
};
bool cmp(sone s1,sone s2){
	if(s1.num!=s2.num)
		return s1.num>s2.num;
	else return s1.time<s2.time;
}
int main(void){
	int n,i,h,mi,sec,g,s,c,m;
	sone *att;
	while(scanf("%d %d %d %d %d",&n,&g,&s,&c,&m)!=EOF&&(n||g||s||c||m)){
		att=new sone[n];
		for(i=0;i<n;i++){
			att[i].id=i+1;
			scanf("%d %d:%d:%d",&att[i].num,&h,&mi,&sec);
			att[i].time=3600*h+60*mi+sec;
		}
		sort(att,att+n,cmp);
		for(i=0;i<n;i++){
			if(att[i].id==m) break;
		}
		printf("Accepted today? I've got a");
		if(i+1<=g) printf(" golden medal :)\n");
		else if(i+1<=g+s) printf(" silver medal :)\n");
		else if(i=1<=g+s+c) printf(" copper medal :)\n");
		else printf("n honor mentioned :)\n");
		delete []att;
	}
	return 0;
}*/