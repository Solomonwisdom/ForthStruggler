////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 10:01:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1334
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,j,k,n;
	for(n=3;n<=200;n++)
		for(i=2;i<n;i++)
			for(j=i;j<n;j++)
				for(k=j;k<n;k++)
					if(n*n*n==(i*i*i+j*j*j+k*k*k))
						cout<<"Cube = "<<n<<", Triple = ("<<i<<','<<j<<','<<k<<')'<<endl;
					return 0;

}