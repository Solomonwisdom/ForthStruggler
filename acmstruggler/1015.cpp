////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 19:40:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
bool visited[13];
char s[13],result[13];
int target,k,len;
bool compare(char a,char b)
{
	return a>b;
}
bool DFS(int cur,int count)
{
	if(count==5){
		if(cur==target) 
			return true;
		else return false;
	}
	int num;
	for(int i=0;i<len;i++)
		if(!visited[i])
		{
			visited[i]=1;
			count++;
			num=s[i]-'A'+1;
			result[k++]=s[i];
			int temp=cur;
			if(count==1)
				cur+=num;
			else if(count==2)
				cur-=pow(float(num),2);
			else if(count==3)
				cur+=pow(float(num),3);
			else if(count==4)
				cur-=pow(float(num),4);
			else cur+=pow(float(num),5);
			if(DFS(cur,count))
				return true;
			k--;
			visited[i]=0;
			cur=temp;
			count--;
		}
	return false;
}
int main(void)
{
	while(true)
	{
		k=0;
		cin>>target;
	    cin>>s;
		if(target==0&&!strcmp(s,"END")) break;
		len=strlen(s);
		for(int i=0;i<len;i++) visited[i]=false;
		sort(s,s+len,compare);
		if(DFS(0,0))
		{
			result[k]='\0';
			cout<<result<<endl;
		}
		else cout<<"no solution"<<endl;
	}
	return 0;
}