////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 08:55:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main(void){
	string shu[10]={"zero","one","two","three","four","five","six","seven","eight","nine"},ch[6];
	int num[10]={0,1,2,3,4,5,6,7,8,9},i,mark,a,b;
	bool flag1,flag2;
	while(true){
		i=0;
		flag1=flag2=false;
		a=0;b=0;
		while(cin>>ch[i]){
			if(ch[i]=="=") break;
			if(ch[i]=="+") mark=i;
			i++;
		}
		if(ch[0]==shu[0]&&ch[2]==shu[0]) break;
		if(mark==1){
			for(int j=0;j<10;j++)
				if(ch[0]==shu[j]){ a=num[j];break;}
		}
		else if(mark==2)
			for(int j=0;j<10;j++){
				if(ch[0]==shu[j]){ a+=10*num[j];flag1=true;}
				if(ch[1]==shu[j]) {a+=num[j];flag2=true;}
				if(flag1&&flag2) break;
			}
		flag1=flag2=false;
		if(i-mark==2){
			for(int j=0;j<10;j++)
				if(ch[mark+1]==shu[j]){ b=num[j];break;}}
		else if(i-mark==3)
			for(int j=0;j<10;j++){
				if(ch[mark+1]==shu[j]){ b+=num[j]*10;flag1=true;}
				if(ch[mark+2]==shu[j]){ b+=num[j];flag2=true;}
				if(flag1&&flag2) break;
			}
		cout<<a+b<<endl;
	}
	return 0;
}