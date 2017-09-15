////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 08:17:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1305
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string s1,string s2){
	return s1.size()<s2.size();
}
int main(void){
	string code[30],temp;
	int n=0,count=0,len;
	bool flag,f;
	while(true){
		n=0;count++;
		flag=true;
		while(true){
			if(cin>>code[n])  f=true;
			else {f=false;break;;}
			if(code[n]=="9") break;
			n++;}
		if(!f) break;
		sort(code,code+n,cmp);
		for(int i=0;i<n-1;i++){
			len=code[i].size();
			for(int j=i+1;j<n;j++){
				temp=code[j].substr(0,len);
				if(temp==code[i]){ flag=false;break;}
			}
			if(!flag){ printf("Set %d is not immediately decodable\n",count);break;}
		}
		if(flag) printf("Set %d is immediately decodable\n",count);
	}
	return 0;
}