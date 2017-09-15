////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 15:56:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,i,j,k,height,up,down,wid;
	char ch;
	cin>>n;
	for(i=0;i<n;i++){
		if(i!=0) cout<<endl;
		cin>>ch>>height;
		wid=height/6+1;
		if(height%2==0){ 
			up=height/2;down=height/2;
		}
		else{ up=height/2+1;down=height/2;}
		for(j=0;j<wid;j++) cout<<' ';
		for(j=0;j<down-1;j++) cout<<ch;
		cout<<endl;
		for(j=0;j<up-2;j++)
		{
			for(k=0;k<wid;k++) cout<<ch;
			for(k=0;k<down-1;k++) cout<<' ';
			for(k=0;k<wid;k++) cout<<ch;
			cout<<endl;
		}
		for(j=0;j<wid;j++) cout<<' ';
		for(j=0;j<down-1;j++) cout<<ch;
		cout<<endl;
		for(j=0;j<down-1;j++)
		{
			for(k=0;k<wid;k++) cout<<ch;
			for(k=0;k<down-1;k++) cout<<' ';
			for(k=0;k<wid;k++) cout<<ch;
			cout<<endl;
		}
		for(j=0;j<wid;j++) cout<<' ';
		for(j=0;j<down-1;j++) cout<<ch;
		cout<<endl;
	}
	return 0;
}