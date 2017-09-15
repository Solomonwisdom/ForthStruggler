////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 18:13:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1320
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int n,*n1,*n2;
	char ch;
	int i,j,k;
	while(cin>>n&&n){
		n1=new int[n+1];
		n2=new int[n+1];
		for(i=1;i<=n;i++)n1[i]=n2[i]=0;
		cin>>ch;
		switch(ch){
		case'P':{
			for(i=1;i<=n;i++) cin>>n1[i];
			for(i=1;i<=n;i++) 
				for(j=1;j<i;j++)
					if(n1[i]<n1[j]) n2[n1[i]]++;
			cout<<n2[1];
			for(i=2;i<=n;i++) cout<<' '<<n2[i];
			cout<<endl;
			break;}
		case'I':{
			for(i=1;i<=n;i++) cin>>n2[i];
			for(i=1;i<=n;i++){
				j=k=1;
				while(true){
					if(n1[k]==0&&j>n2[i]) break;
					if(n1[k]==0) j++;
					k++;
				}
				n1[k]=i;
			}
			cout<<n1[1];
			for(i=2;i<=n;i++) cout<<' '<<n1[i];
			cout<<endl;
			break;}
		}
		delete []n1;
		delete []n2;
	}
	return 0;
}