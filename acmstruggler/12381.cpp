////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 13:41:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1238
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1692KB
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
/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string s1,string s2)
{
	return s1.size()<s2.size();
}
int main(void){
	int n,t,i,j,len,k;
	string *str,substr,revstr;
	bool jud;
	cin>>t;
	while(t--){
		cin>>n;
		str=new string[n];
		for(i=0;i<n;i++)
			cin>>str[i];
		sort(str,str+n,cmp);
		len=str[0].size();
		for(i=str[0].size();i>=0;i--){
			jud=false;
			for(j=0;j<=len-i;j++)
			{
				substr=str[0].substr(j,i);
				revstr=substr;
				reverse(revstr.begin(),revstr.end());
				for(k=0;k<n;k++)
					if( str[k].find(substr)>str[k].size()&&str[k].find(revstr)>str[k].size())
						break;
				if(k==n){ jud=true;break;}
			}
			if(jud){ cout<<i<<endl;break;}
		}
	    if(i==0) cout<<0<<endl;
	}
	return 0;
}*/