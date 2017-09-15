////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 14:19:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string x,y;
    while(cin>>x>>y){
        string x1,y1;
        if(x.find('.')!=string::npos){
            int k=x.find('.');
            x1.assign(x,k+1,x.size()-k);///x小数部分
            x.erase(k);///x整数部分
        }
        if(y.find('.')!=string::npos){
            int k=y.find('.');
            y1.assign(y,k+1,y.size()-k);///y的小数部分
            y.erase(k);///y整数部分
        }
        if(x.size()>y.size())
            swap(x,y);
        reverse(x.begin(),x.end());///x反向   
        reverse(y.begin(),y.end());///y反向 
        
        if(x1.size()>y1.size()) swap(x1,y1);
        
        string v=""; 
        v.assign(y1,x1.size(),y1.size()-x1.size());
        
        if(!v.empty()) reverse(v.begin(),v.end());  /// 较多小数的那个多出来的小数部分
        y1.erase(x1.size()); ///减去多余小数之后的小数
        
        string s="";  s+=v;
        int p=0,i=0;
        for(i=x1.size()-1;i>=0;--i){  ///从小数开始算
            p+=(x1[i]-'0')+(y1[i]-'0');
            s+=char(p%10+'0');
            p/=10;
        }
        s+='.';
        for(i=0;i<y.size();++i){     ///加上两整数部分
            if(i<x.size())
                p+=(x[i]-'0')+(y[i]-'0');
            else 
                p+=(y[i]-'0');
            s+=char(p%10+'0');
            p/=10;
        }
        while(p){              
            s+=char(p%10+'0');
            p/=10;
        }
        while(s[0]=='0'||s[0]=='.'&&s.size()){  ///清除小数点后的无效0
            int t=0;
            if(s[0]=='.')t=1;
            s.erase(0,1);
            if(t)break;///整数部分的0不能删
        }
        if(s.empty()) s+='0'; 
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}/*
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	int sum[500];
	string s1,s2;
	int n,i,j,k,jia,max;
	int p1,p2;
	while(cin>>s1>>s2){
		memset(sum,0,sizeof(sum));
	    for(p1=0;p1<s1.size()-1&&s1[p1]!='.';p1++);
		for(p2=0;p2<s2.size()-1&&s2[p2]!='.';p2++);
		if((s1.size()-p1)<s2.size()-p2){
			string temp;
			int t;
			temp=s1;
			s1=s2;
			s2=temp;
			t=p1;
			p1=p2;
			p2=t;
		}
		max=p1>p2?p1:p2;
		p1=s1.size()-1-p1;
		p2=s2.size()-1-p2;
		for(i=0;i<p1-p2;i++)
			s2+='0';
		jia=0;
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		for(j=k=i=0;i<s1.size()||k<s2.size();j++){
			if(i<s1.size()&&s1[i]=='.') i++;
			if(k<s2.size()&&s2[k]=='.') k++;
			if(i<s1.size()){ sum[j]+=s1[i]-'0';i++;}
			if(k<s2.size()){ sum[j]+=s2[k]-'0';k++;}
			sum[j]+=jia;
			jia=sum[j]/10;
			sum[j]%=10;
		}
		if(jia){
			sum[j++]=1;
			max++;
		}
		if(p1==0&&p2==0){
			for(i=j-1;i>=0;i--)
				printf("%d",sum[i]);
			printf("\n");
			continue;
		}
		for(i=j-1,k=0;i>=0&&k<max;i--,k++){
			printf("%d",sum[i]);
		}
		n=0;
		while(sum[n]==0) n++;
		if(n<i+1){
			printf(".");
			while(i>=n) printf("%d",sum[i--]);
		}
        printf("\n");
	}
	return 0;
}*/