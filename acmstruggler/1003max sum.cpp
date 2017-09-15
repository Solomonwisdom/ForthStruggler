////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 15:33:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2848KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>

using namespace std;

int MaxSubSum(const vector<int>& arr,int& start,int& end)
{
	start=0;
	end=0;
	if(&arr==NULL) return -1;
	if(arr.size() == 0) return -1;

	int sum=arr.at(0);
	int lastSum=arr.at(0);
	int tmpStart=0,tmpEnd=0;
	for(int i=1;i<arr.size();i++)
	{
		if(lastSum<0)
		{
			lastSum=arr.at(i);
			tmpStart=i;
		}
		else
		{
			lastSum+=arr.at(i);
			tmpEnd=i;
		}

		if(lastSum>sum)
		{
			sum=lastSum;
			if(lastSum>0)
			{
				start=tmpStart;
				end=tmpEnd;
			}
			else
			{
				start=tmpStart;
				end=tmpStart;
			}
		}
	}
	return sum;
}

int main()
{
	//Case Count T
	int		T;
	cin>>T;

	//Case Items;
	vector<vector<int>> items;
	while(T--)
	{
		//Case Length N;
		int N;
		cin>>N;

		if(N<1 || N>100000) return -1;	//exception

		//Case Items;
		vector<int> tmpList;
		int tmp;
		for(int i=0;i<N;i++) 
		{
				cin>>tmp;
				if( tmp<-1000 || tmp >1000) return -1;
				tmpList.push_back(tmp);
		}
		items.push_back(tmpList);
	}

	for(int i=0;i<items.size();i++)
	{
		//foreach case
		int start,end,sum;
		sum=MaxSubSum(items.at(i),start,end);
		cout<<"Case "<<i+1<<":"<<endl;
		cout<<sum<<" "<<start+1<<" "<<end+1<<endl;

		if(i<items.size()-1)
			cout<<endl;

	}
	return 0;
}