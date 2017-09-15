////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 12:53:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1342
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,*s;
	int i,j,k,m,r,t,q=0;
	while(cin>>n&&n){
		if(q!=0) cout<<endl;
		q++;
		s=new int[n];
		for(i=0;i<n;i++) cin>>s[i];
		for(i=0;i<n-5;i++)
			for(j=i+1;j<n-4;j++)
				for(k=j+1;k<n-3;k++)
					for(m=k+1;m<n-2;m++)
						for(r=m+1;r<n-1;r++)
							for(t=r+1;t<n;t++)
								printf("%d %d %d %d %d %d\n",s[i],s[j],s[k],s[m],s[r],s[t]);
		delete []s;
	}
	return 0;
}