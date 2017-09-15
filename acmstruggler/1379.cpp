////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 15:59:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1379
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct sortde{
	string s;
	int num;
};
bool cmp(sortde s1,sortde s2){
	return s1.num<s2.num;
}
int main(void){
	int N,n,m;
	sortde *ss;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&n,&m);
		getchar();
		ss=new sortde[m];
		for(int i=0;i<m;i++){
			cin>>ss[i].s;
			ss[i].num=0;
			for(int j=0;j<n-1;j++)
				for(int k=j+1;k<n;k++)
					if(ss[i].s[k]<ss[i].s[j]) ss[i].num++;
		}
		sort(ss,ss+m,cmp);
		for(int i=0;i<m;i++)
			cout<<ss[i].s<<endl;
	}
	return 0;
}