////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 20:17:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:2984KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct student{
	string id;
	int soccer;
};
bool cmp(student s1,student s2){
	if(s1.soccer!=s2.soccer)
		return s1.soccer>s2.soccer;
	else return s1.id<s2.id;
}
int main(void){
	int n,m,g,fm,pn;
	int *pro;
	student *stu;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d %d",&m,&g);
		pro=new int[m];
		stu=new student[n];
		for(int i=0;i<m;i++)
			scanf("%d",&pro[i]);
		for(int i=0;i<n;i++){
			cin>>stu[i].id;
			stu[i].soccer=0;
			scanf("%d",&fm);
			while(fm--){
				scanf("%d",&pn);
				stu[i].soccer+=pro[pn-1];
			}
		}
		sort(stu,stu+n,cmp);
		int i;
		for(i=0;i<n;i++)
			if(stu[i].soccer<g) break;
		printf("%d\n",i);
		for(int j=0;j<i;j++){
			cout<<stu[j].id;
			printf(" %d\n",stu[j].soccer);
		}
	}
	return 0;
}