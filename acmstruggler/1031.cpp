////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 09:20:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1031
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,m,k,i,j;
	double *ass,*fac,t;
	bool *isDis,p;
	while(cin>>n>>m>>k)
	{
		ass=new double[m];
		fac=new double[m];
		isDis=new bool[m];
		for(i=0;i<m;i++){ ass[i]=0;isDis[i]=false;}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				cin>>t;
				ass[j]+=t;
				fac[j]=ass[j];
			}
		sort(fac,fac+m);
		for(j=0;j<k;j++)
			for(i=0;i<m;i++)
				if(ass[i]==fac[m-j-1]&&!isDis[i]){
					isDis[i]=true;
				    break;
				}
		p=false;
		for(i=m-1;i>=0;i--)
			if(isDis[i]){
				if(!p) p=true;
				else cout<<' ';
				cout<<i+1;
			}
		cout<<endl;
		delete []ass;
		delete []fac;
		delete []isDis;
	}
	return 0;
}