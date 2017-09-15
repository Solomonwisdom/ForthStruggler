////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 13:52:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
bool isVo(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		return true;
	else return false;
}
int main(void)
{
	char pa[21];
	int len,Voc;
	bool ok;
	while(cin>>pa)
	{
		ok=true;
		Voc=0;
		if(strcmp(pa,"end")==0) break;
		len=strlen(pa);
		for(int i=0;i<len;i++){
			if(i>0&&pa[i]==pa[i-1]&&pa[i]!='e'&&pa[i]!='o'){
				ok=false;break;}
			if(isVo(pa[i])) Voc++;
			if(i>1&&isVo(pa[i-2])==isVo(pa[i-1])&&isVo(pa[i-1])==isVo(pa[i])){
				ok=false;break;
			}
		}
		if(Voc==0) ok=false;
		if(ok) cout<<"<"<<pa<<"> is acceptable."<<endl;
		else cout<<"<"<<pa<<"> is not acceptable."<<endl;
	}
	return 0;
}