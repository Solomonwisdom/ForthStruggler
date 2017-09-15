////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 15:00:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1152
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1712KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,i,x,y,st,ol;
	int *px,*py;
	while(cin>>n&&n)
	{
		st=ol=0;
		px=new int[n];
		py=new int[n];
		for(i=0;i<n;i++)
			cin>>px[i]>>py[i];
		x=px[n/2];
		y=py[n/2];
		for(i=0;i<n;i++){
			if((px[i]>x&&py[i]>y)||(px[i]<x&&py[i]<y))
				st++;
			if((px[i]>x&&py[i]<y)||(px[i]<x&&py[i]>y))
				ol++;
		}
		cout<<st<<' '<<ol<<endl;
		delete []px;
		delete []py;
	}
	return 0;
}