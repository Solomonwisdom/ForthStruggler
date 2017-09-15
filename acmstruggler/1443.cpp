////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 20:02:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1443
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[14];
int main()
{
    int k;
    a[1]=2;
    for(int i=2; i<14; i++)
    {
        for(int m=i+1;; m++)
        {
            int s=0,j=2*i;
            while(1)
            {
                int x=(s+m)%j;
                if(!x)
                    x=j;
                if(x<=i)
                    break;
                s=x-1;
                j--;
                if(j==i)
                {
                    a[i]=m;
                    break;
                }
            }
            if(j==i)
                break;
        }
    }
    while(cin>>k&&k)
        cout<<a[k]<<endl;
    return 0;
}