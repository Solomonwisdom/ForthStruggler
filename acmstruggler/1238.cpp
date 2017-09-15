////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 13:13:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1238
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(const string &s1,const string &s2)
{
    return s1.length()<s2.length();
}
string a[101];
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    while(n--)
    {

        scanf("%d",&m);
        int m1=m;
        int q=0;
        while(m--)
        {
            cin>>a[q++];
        }
        sort(a,a+m1,cmp);
        string substring;
        string reverseString;
        int i=a[0].size();
        for(;i>0;i--)
        {
             bool is=false;
            for(int j=0;j<a[0].size();j++)
        {
            if(i+j>a[0].size())
            break;

            substring=a[0].substr(j,i);
            reverseString=substring;
            reverse(reverseString.begin(),reverseString.end());
            int k=1;
            for(;k<m1;k++)
            {
                if(a[k].find(substring)>a[k].size()&&a[k].find(reverseString)>a[k].size())
                {
                    break;
                }
            }
            if(k==m1)
            {
                is=true;
                break;
            }
        }
        if(is)
        {
            cout<<i<<endl;
            break;
        }

        }
        if(i==0)
        {
            printf("0\n");
        }
    }
}