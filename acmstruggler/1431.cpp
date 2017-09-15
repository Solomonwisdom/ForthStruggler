////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 19:30:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1431
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool ispalind(int n){
	int s=0,t=n;
	while(t){
		s=s*10+t%10;
		t/=10;
	}
	if(n==s) return true;
	else return false;
}
bool isprime(int n){
	if(n==2) return true;
	for(int i=2;i<=sqrt(double(n));i++)
		if(n%i==0) return false;
	return true;
}
int main(void){
	int num1,num2;
	while(cin>>num1>>num2){
		while(num1<=num2&&num1<=9989899)
			if(ispalind(num1))
			{
				if(isprime(num1)) printf("%d\n",num1++);
				else num1++;
			}
			else num1++;
		printf("\n");
	}
	return 0;
}