////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-16 22:05:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1084
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
using std::sort;

struct Node{
	int pos, num, s, val;
} stu[102];
int arr[6];

bool cmp1(Node a, Node b)
{
	if(a.num == b.num) return a.s < b.s;
	return a.num > b.num;
}

bool cmp2(Node a, Node b)
{
	return a.pos < b.pos;
}

int main()
{
	int n, h, m, s, num;
	while(scanf("%d", &n) == 1 && n > 0){
		for(int i = 1; i < 6; ++i) arr[i] = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d:%d:%d", &num, &h, &m, &s);
			s += m * 60 + h * 3600;
			
			stu[i].pos = i;
			stu[i].num = num;
			stu[i].s = s;
			stu[i].val = 100 - (5 - num) * 10;
			++arr[num];
		}
		
		sort(stu, stu + n, cmp1);
		
		for(int i = 4, pos = 0; i; --i){
			if(arr[i]){
				while(stu[pos].num != i) ++pos;
				if(arr[i] == 1) stu[pos++].val += 5;			
				for(int j = 0; j < arr[i] / 2; ++j)
					stu[pos++].val += 5;
			}
		}
		
		sort(stu, stu + n, cmp2);
		
		for(int i = 0; i < n; ++i)
			printf("%d\n", stu[i].val);
		printf("\n");
	}
	return 0;
}
/*#include<iostream>
#include<algorithm>
using std::sort;
typedef struct{
	int p;
	int time;
	int id;
	int grade;
}stu;
bool compare1(stu s1,stu s2)
{
	if(s1.p==s2.p)
		return s1.time<s1.time;
	return s1.p>s2.p;
}
bool compare2(stu s1,stu s2)
{
	return s1.id<s2.id;
}
int main(void)
{
	int n,h,m,s,i,j,k,num;
	stu *st;
	int v[6];
	while(scanf("%d", &n) == 1 && n > 0)
	{
		st=new stu[n];
		for(i=1;i<6;i++) v[i]=0;
		for(i=0;i<n;i++){
			st[i].id=i;
			scanf("%d %d:%d:%d", &num, &h, &m, &s);
			s+=h*3600+m*60;
			st[i].p=num;
			st[i].time=s;
			st[i].grade=50+num*10;
			v[num]++;
		}
		sort(st,st+n,compare1);
		for(k=0,i=4;i;i--)
		{
			if(v[i]){
				while(st[k].p != i) ++k;
				if(v[i] == 1) st[k++].grade += 5;			
				for(int j = 0; j <v[i] / 2; ++j)
					st[k++].grade += 5;
			}
		}
		sort(st,st+n,compare2);
		for(i=0;i<n;i++) printf("%d\n",st[i].grade);
		printf("\n");
		delete []st;
	}
	return 0;
}*/