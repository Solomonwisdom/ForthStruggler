////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 10:15:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1033
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	char str[201],dir;
	int x,y;
	while(cin>>str)
	{
		x=310;
		y=420;
		dir='s';
		cout<<"300 420 moveto"<<endl;
		cout<<"310 420 lineto"<<endl;
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='A')
			{
				switch(dir){
				case's': y-=10;dir='a';break;
				case'a': x-=10;dir='w';break;
				case'w': y+=10;dir='d';break;
				case'd': x+=10;dir='s';break;
				}
				cout<<x<<' '<<y<<" lineto"<<endl;
			}
			else
			{
				switch(dir){
				case's': y+=10;dir='d';break;
				case'a': x+=10;dir='s';break;
				case'w': y-=10;dir='a';break;
				case'd': x-=10;dir='w';break;
				}
				cout<<x<<' '<<y<<" lineto"<<endl;
			}
		}
		cout<<"stroke"<<endl;
		cout<<"showpage"<<endl;
	}
	return 0;
}