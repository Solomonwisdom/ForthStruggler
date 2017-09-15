////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 17:32:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num;
	int i=0,j=0,k=0;
	bool flag;
	while(cin>>num)
	{
		flag=true;
		for(i=1;i*i<num;i++)
		{
			for(j=i;j*j<=num-i;j++)
			{
				for(k=j;k*k<=num-i-j;k++)
				{
					if(i*i+j*j+k*k==num)
					{
						cout<<i<<' '<<j<<' '<<k<<endl;
						flag=false;
						break;	
					}
					else 
						continue;
					
				}
				if(flag==false)
						break;
			}
			if(flag==false)
						break;
		}
		i=0;j=0;k=0;
	}
	return 0;
}