////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 12:52:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int T,len1,len2,len,i,j;
	char shu1[1000],shu2[1000],sum[1001];
	cin>>T;
	for(i=1;i<=T;i++)
	{
		if(i!=1) cout<<endl;
		cin>>shu1;
		cin>>shu2;
		len1=strlen(shu1);
		len2=strlen(shu2);
		len=(len1>len2?len1:len2);
		len1--;len2--;
		for(j=0;j<=len;j++) sum[j]='0';
		for(j=len;len1>=0&&len2>=0;j--){
			sum[j]+=shu1[len1--]+shu2[len2--]-'0'-'0';
			if(sum[j]>'9'){
				sum[j-1]++;
				sum[j]-=10;
			}
		}
		while(len1>=0) sum[j--]+=shu1[len1--]-'0';
		while(len2>=0) sum[j--]+=shu2[len2--]-'0';
		if(sum[0]=='0'){
			for(j=0;j<len;j++) sum[j]=sum[j+1];
			sum[len]='\0';}
		else sum[len+1]='\0';
		cout<<"Case "<<i<<":"<<endl;
		cout<<shu1<<" + "<<shu2<<" = "<<sum<<endl;
	}
	return 0;
}