////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-16 16:28:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct{
	int row,col;
	char name;
}matrix;
int main(void)
{
	int n,sum,a,b,c,d;
	bool tag;
	stack<int> row,col;
	string exp;
	char m;
	matrix mat[26];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		mat[int(m)-65].name=m;
		cin>>mat[int(m)-65].row>>mat[int(m)-65].col;
	}
	while(cin>>exp)
	{
		sum=0;tag=true;
		for(int i=0;i<exp.size();i++){
			if(exp[i]!='('&&exp[i]!=')')
			{
				row.push(mat[int(exp[i])-65].row);
				col.push(mat[int(exp[i])-65].col);
			}
			else if(exp[i]==')')
			{
				a=row.top();row.pop();
				b=row.top();row.pop();
				c=col.top();col.pop();
				d=col.top();col.pop();
				if(d!=a){
					tag=false;
					cout<<"error"<<endl;
					break;
				}
				sum+=b*a*c;
				row.push(b);
				col.push(c);
			}
		}
		if(tag){
			row.pop();
			col.pop();
			cout<<sum<<endl;
		}
	}
	return 0;
}