////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 15:36:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1239
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool prime(int i){
	if(i==1) return false;
	if(i==2) return true;
	bool ok=true;
	for(int j=2;j<=sqrt(double(i));j++)
		if(i%j==0){ok=false; break;}
	return ok;
}
int main(void){
	int n,b,a,i,j;
	double c;
	bool flag;
	while(cin>>n>>a>>b&&n&&a&&b)
	{
		c=1.0*a/b;
		flag=false;
		for(i=n;i>=4&&!flag;i--){
			if(!prime(i))
				for(j=2;j<=sqrt(double(i));j++){
					if(i%j==0)
						if(prime(j)&&prime(i/j)&&(1.0*j/(i/j))>=c&&(1.0*j/(i/j))<=1)
						{printf("%d %d\n",j,i/j);flag=true;break;}
				}
		}
		/*max=0;
		for(i=2;i<=sqrt(1.0*n);i++)
			for(j=i;i*j<=n&&(double(i)/j)>=c;j++)
				if(prime(i)&&prime(j)&&max<i*j){ max=i*j;p=i;q=j;}*/
	}
	return 0;
}