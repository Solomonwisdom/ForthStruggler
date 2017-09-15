////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 09:51:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int count(int x,int cnt)
{
	cnt++;
	while (x != 1){
		cnt++;
	if (x % 2 == 1) x = 3 * x + 1;
	else x = x / 2;
	}
	return cnt;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int max = 0;
		if (m > n)
			for (int i = m; i >= n; --i)
			{
				if (count(i, 0) > max)
					max = count(i, 0);
			}
		else for (int i = m; i <= n; ++i)
		{
			if (count(i, 0) > max)
				max = count(i, 0);
		}
		cout << m << " " << n << " " << max << endl;
	}
}
/*#include<iostream>
using namespace std;
int getlen(int i)
{
	int length=0;
	while(true)
	{
		length++;
		if(i==1) break;
		if(i%2) i=3*i+1;
		else i/=2;
	}
	return length;
}
int main(void)
{
	int m,n,max;
	while(cin>>m>>n)
	{
		max=1;
		for(int i=m;i<=n;i++)
			max=(max<getlen(i))? getlen(i):max;
		cout<<m<<' '<<n<<' '<<max<<endl;
	}
	return 0;
}*/