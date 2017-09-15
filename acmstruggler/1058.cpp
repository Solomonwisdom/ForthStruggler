////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-30 17:54:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int min(int a,int b){
	return a>b?b:a;
}
int min4(int a,int b,int c,int d){
	return min(min(a,b),min(c,d));
}
int main(char argc,char *argv[])
{
	int disk[5844];
	int n,p1,p2,p3,p4;
	disk[1]=1;
	n=2;
	p1=p2=p3=p4=1;
	while(n<5844){
		disk[n]=min4(2*disk[p1],3*disk[p2],5*disk[p3],7*disk[p4]);
		if(disk[n]==2*disk[p1])
			p1++;
		if(disk[n]==disk[p2]*3)
			p2++;
		if(disk[n]==5*disk[p3])
			p3++;
		if(disk[n]==7*disk[p4])
			p4++;
		n++;
	}
	while(scanf("%d",&n)!=EOF&&n){
		printf("The %d",n);
		int ten=n/10%10;
		if(ten!=1&&n%10==1)
			printf("st ");
		else if(ten!=1&&n%10==2)
			printf("nd ");
		else if(ten!=1&&n%10==3)
			printf("rd ");
		else printf("th ");
		printf("humble number is %d.\n",disk[n]);
	}
	return 0;
}