////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 20:50:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<assert.h>
using namespace std;
const int m=40;
const int s=10;
template<class T>
class SeqStack
{
private:
	T *ele;
	int top;
	int maxsize;
public:
	SeqStack(int sz=m)
	{ ele=new T[sz];maxsize=sz;top=-1; }
	~SeqStack() { delete []ele;}
	T GetHead() { assert(!IsEmpty()); return ele[top];}
	int GetSize() { return top+1;}
	bool IsEmpty()
	{ return top==-1; }
	bool IsFull(){
		return top==maxsize-1; }
	void expand();
	void MakeEmpty()  { top=-1;}
	void push(T x);
	T pop();
};

template<class T>
void SeqStack<T>::push(T x)
{
	if(IsFull())expand();
	ele[++top]=x;
}

template<class T>
T SeqStack<T>::pop()
{
	assert(!IsEmpty());
	T x=ele[top--];
	return x;
}

template<class T>
void SeqStack<T>::expand()
{
	T *newele=new T[maxsize+s];
	for(int i=0;i<maxsize;i++)
		newele[i]=ele[i];
	delete []ele;
	maxsize+=s;
	ele=newele;
}
int isp(char ch)
{
	switch(ch)
	{
	case'#': return 0;
	case'(': return 1;
	case'*':
	case'/': return 5;
	case'+': 
	case'-': return 3;
	case')': return 6;
	default: return -1;
	}
}
int icp(char ch)
{
	switch(ch)
	{
	case'#': return 0;
	case'(': return 6;
	case'*':
	case'/': return 4;
	case'+': 
	case'-': return 2;
	case')': return 1;
	default: return -1;
	}
}
bool IsDigit(char ch)
{
    if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0')
		return true;
	else
		return false;
}
void Postfix(char *mids,char *suffixs)
{
	SeqStack<char> S;
	int i=0,j=0;
	char op,ch=mids[0],ch1;
	S.push('#');
	while(ch!='#'||S.GetHead()!='#')
	{
		if(IsDigit(ch))
		{
			if(i>0 && !IsDigit(mids[j-1]) && suffixs[i-1]!='.')
				suffixs[i++]=' ';
			suffixs[i++]=ch;
			ch=mids[++j];
		}
		else if(ch=='.')
		{
			suffixs[i++]=ch;
			ch=mids[++j];
		}
		else
		{
			ch1=S.GetHead();
			if(isp(ch1)<icp(ch))
			{
				S.push(ch);
				ch=mids[++j];
			}
			else if(isp(ch1)>icp(ch))
			{
				op=S.pop();
				suffixs[i++]=op;
			}
			else
			{
				op=S.pop();
				if(op='(' ) ch=mids[++j];
			}
		}
	}
	suffixs[i++]='#';
}
double PartCalculate(double a,char ch,double b)
{
	switch(ch)
	{
	case'+': return a+b;
	case'-': return a-b;
	case'*': return a*b;
	case'/': return a/b;
	default: return -1;
	}
}
double calculate(char *suffixs)
{
	int i=0;
	char ch=suffixs[i];
	double x,a,b,y;
	SeqStack<double> S;
	do{
		if(IsDigit(ch))
		{
			x=0;
			while(IsDigit(ch))
			{
				x=10*x+(ch-'0');
				ch=suffixs[++i];
			}
			if(ch=='.')
			{
				int count=1; y=0;
				ch=suffixs[++i];
				while(IsDigit(ch))
				{
					count*=10;
					y=10*y+(ch-'0');
					ch=suffixs[++i];
				}
				y/=count;
				x+=y;
			}
			if(ch==' ') ch=suffixs[++i];
			S.push(x);
		}
		else
		{
			b=S.pop();
			a=S.pop();
			S.push(PartCalculate(a,ch,b)); 
			ch=suffixs[++i];
			if(ch==' ') ch=suffixs[++i];
		}
	}while(ch!='#');
	x=S.pop();
	return x;
}
int main(void)
{
	char a[300],exp[300],suffixs[600];
	int i,j;
	while(gets(a)&&strcmp(a,"0")){
    	for(i=j=0;i<strlen(a);i++)
			if(a[i]!=' ') exp[j++]=a[i];
		exp[j]='#';
    	Postfix(exp,suffixs);
    	printf("%.2lf\n",calculate(suffixs));
	}
	return 0;
}
