////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 09:04:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1306
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string s1,s2,t1,t2,x1,x2;
	int i,j,k,n;
	while(cin>>x1&&x1!="-1")
	{
		cin>>x2;
		if(x1.length()>x2.length())
		{
			s1=x2;
			s2=x1;
		}
		else
		{
			s1=x1;
			s2=x2;
		}
		int sum=0;
		for(i=0;i<s1.length();i++)
			for(k=0;k<s2.length();k++)
                 for(j=1;j<=s1.length()-i&&j<=s2.length()-k;j++)
				 {
					 int total=0;
						t1=s1.substr(i,j);
						t2=s2.substr(k,j);
						for(n=0;n<j;n++)
							if(t1[n]==t2[n])
								total++;
							if(total>sum)
								sum=total;
				 }
             int temp=x1.length()+x2.length();
			 int t=sum*2;
			 if(sum==0)
			 cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<"0"<<endl;
			 else if(t==temp)
			 cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<"1"<<endl;
			 else
			 {
				 for(i=2;i<temp;i++)
				 if(temp%i==0&&t%i==0)
				 {
					 while(temp%i==0&&t%i==0)
					 {
						 t/=i;
					     temp/=i;
					 }
				 }
             cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<t<<"/"<<temp<<endl;
			 }
	}
	return 0;
}/*
#include<iostream>
#include<string>
using namespace std;
int main(void){
	string str1,str2,temp1,temp2;
	int i,j,k,n,count,max,t1,t2,a,b,r;
	while(cin>>str1){
		if(str1=="-1") break;
		cin>>str2;
		if(str1==str2) {
			cout<<"appx("<<str1<<','<<str2<<") = 1"<<endl;
			continue;
		}
		max=0;
		for(i=0;i<str1.size();i--)
			for(j=0;j<=str2.size();j++)
				for(k=1;k<=str1.size()-i&&k<=str2.size()-j;k++){
					count=0;
					temp1=str1.substr(i,k);
					temp2=str2.substr(j,k);
					for(n=0;n<k;n++)
						if(temp1[n]==temp2[n]) count++;
					max=max<count?count:max;
				}
		if(max==0){cout<<"appx("<<str1<<','<<str2<<") = 0"<<endl;continue;}
		a=t1=max*2;
		b=t2=str1.size()+str2.size();
		r=b;
		while(true){
			r=a%b;
			if(r==0) break;
			a=b;
			b=r;
		}
		t1/=b;
		t2/=b;
		cout<<"appx("<<str1<<','<<str2<<") = "<<t1<<'/'<<t2<<endl;
	}
	return 0;
}*/