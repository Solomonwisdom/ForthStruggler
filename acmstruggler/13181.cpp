////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 17:16:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1318
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char const *ch = "AEHIJLMOSTUVWXYZ12358";
char const *re = "A3HILJMO2TUVWXY51SEZ8";
bool is_palindrome(string s){
	string temp=s;
	reverse(temp.begin(),temp.end());
	if(temp==s) return true;
	else return false;
}
bool is_mirrored(string s){
	string temp=s;
	int i,j,k;
	reverse(temp.begin(),temp.end());
	for(i=0;i<s.size()/2+1;i++){
		for(j=0;j<21;j++)
			if(s[i]==ch[j]) break;
		if(j==21)break;
		for(k=0;k<21;k++)
			if(temp[i]==re[k]) break;
		if(k==21) break;
		if(j!=k) break;
	}
	if(i==s.size()/2+1) return true;
	else return false;
}
int main(void)
{
	string str;
	while(cin>>str){
		if(is_mirrored(str)){
			if(is_palindrome(str)) cout<<str<<" -- is a mirrored palindrome."<<endl;
			else cout<<str<<" -- is a mirrored string."<<endl;}
		else {
			if(is_palindrome(str)) cout<<str<<" -- is a regular palindrome."<<endl;
			else cout<<str<<" -- is not a palindrome."<<endl;}
		cout<<endl;
	}
	return 0;
}