////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 18:55:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1828KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int *s1,*s2,*s;
	int n,m,i,j,k;
	while(cin>>n>>m){
		s1=new int[n];
		s2=new int[m];
		s=new int[m+n];
		for(i=0;i<n;i++)
			scanf("%d",&s1[i]);
		for(i=0;i<m;i++)
			scanf("%d",&s2[i]);
		sort(s1,s1+n);
		sort(s2,s2+m);
		for(i=0,j=0,k=0;j<n&&k<m;i++){
			if(s1[j]<s2[k]) s[i]=s1[j++];
			else if(s1[j]>s2[k]) s[i]=s2[k++];
			else{
				s[i]=s1[j++];
				k++;
			}
		}
		while(j<n) s[i++]=s1[j++];
		while(k<m) s[i++]=s2[k++];
		printf("%d",s[0]);
		for(j=1;j<i;j++)printf(" %d",s[j]);
		printf("\n");
		delete []s1;
		delete []s2;
		delete []s;
	}
	return 0;
}