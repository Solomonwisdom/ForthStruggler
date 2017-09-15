////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 09:40:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1327
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
bool alp[26];
int main(void){
    int n,count=0;
	char c1,c2,c3;
	bool flag;
	while(scanf("%d",&n)){
		if(n==0) break;
		alp[0]=true;
		count++;
		flag=false;
		for(int i=1;i<26;i++) alp[i]=false;
		for(int i=0;i<n;i++){
			cin>>c1>>c2>>c3;
			if(alp[c3-'a']) 
				alp[c1-'a']=true;
			else alp[c1-'a']=false;
		}
		printf("Program #%d\n",count);
		for(int i=0;i<26;i++)
			if(alp[i]){
				printf("%c ",char('a'+i));
				flag=true;}
		if(!flag) printf("none");
		printf("\n\n");
	}
    return 0;
}