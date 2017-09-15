////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 11:11:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1311
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
struct person{
	string name;
	int age;
};
struct fc{
	string fn,cn;
	int age;
};
bool cmp(person p1,person p2){
	if(p1.age!=p2.age)
		return p1.age>p2.age;
	else return p1.name<p2.name;
}
int main(char argc,char *argv[])
{
	int t,n,i;
	person *family;
	fc *data;
	queue<person> s;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		family=new person[n+1];
		family[0].name="Ted";
		family[0].age=100;
		s.push(family[0]);
		data=new fc[n];
		for(i=0;i<n;i++)
			cin>>data[i].fn>>data[i].cn>>data[i].age;
		int count=1;
		while(count<=n){
			person temp=s.front();
			s.pop();
			for(i=0;i<n;i++)
				if(data[i].fn==temp.name){
					family[count].name=data[i].cn;
					family[count].age=temp.age-data[i].age;
					s.push(family[count]);
					count++;
				}
		}
		sort(family+1,family+n+1,cmp);
		printf("DATASET %d\n",k);
		for(i=1;i<=n;i++)
			cout<<family[i].name<<' '<<family[i].age<<endl;
	}
	return 0;
}