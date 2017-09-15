////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 21:24:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stack>
using namespace std;
int main(void)
{
	int n,*order;
	char *in,*out;
	bool judge;
	while(cin>>n){
		judge=true;
		stack<char> trains;
		int a=0,b=0;
		in=new char[n+1];
		out=new char[n+1];
		order=new int[2*n];
		cin>>in>>out;
		for(int i=0;;i++){
			if(i>2*n){
				judge=false;
				break;
			}
			if(!trains.empty()&&trains.top()==out[b])
			{
				b++;
				trains.pop();
				order[i]=1;
				if(trains.empty()&&b==n)
					break;
			}
			else {
				if(a==n) continue;
				trains.push(in[a++]);
				order[i]=0;
			}
		}
		if(!judge){ cout<<"No."<<endl; cout<<"FINISH"<<endl;}
		else {
			cout<<"Yes."<<endl;
			for(int j=0;j<2*n;j++)
				if(order[j]) cout<<"out"<<endl;
				else cout<<"in"<<endl;
			cout<<"FINISH"<<endl;
		}
		delete []in;delete []out;delete []order;
	}
	return 0;
}