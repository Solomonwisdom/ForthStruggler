////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 17:49:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1274
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1704KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stack>
#include<string>
using namespace std;
string deal(string s){
	string ss;
	int n,m;
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='('||(s[i]<='9'&&s[i]>='0'))
			st.push(s[i]);
		else if(s[i]>='a'&&s[i]<='z'){
			if(st.top()<='9'&&st.top()>='0')
			{
				n=st.top()-'0';
				st.pop();
				m=1;
				while(!st.empty()&&st.top()<='9'&&st.top()>='0'){
					m*=10;
					n+=(st.top()-'0')*m;
					st.pop();
				}
				while(n--)
					st.push(s[i]);
			}
			else st.push(s[i]);
		}
		else if(s[i]==')'){
			string temp;
			while(st.top()!='('){
				temp.insert(temp.begin(),st.top());
				st.pop();
			}
			st.pop();
			if(st.empty()||!(st.top()<='9'&&st.top()>='0')) n=1;
			else {
				n=st.top()-'0';
				st.pop();
				m=1;
				while(!st.empty()&&st.top()<='9'&&st.top()>='0'){
					m*=10;
					n+=(st.top()-'0')*m;
					st.pop();
				}
			}
			while(n--) {
				for(int j=0;j<temp.size();j++)
					st.push(temp[j]);
			}
		}
	}
	while(!st.empty()){
		ss.insert(ss.begin(),st.top());
	    st.pop();
	}
	return ss;
}
int main(void){
	int n;
	string exp;
	scanf("%d",&n);
	while(n--){
		cin>>exp;
		cout<<deal(exp)<<endl;
	}
	return 0;
}