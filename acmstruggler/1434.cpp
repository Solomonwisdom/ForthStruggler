////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-31 09:48:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1434
////Problem Title: 
////Run result: Accept
////Run time:1263MS
////Run memory:19300KB
//////////////////System Comment End//////////////////
#include<cstdio>  
#include<cstring>  
#include<queue>  
#define max 10000+100  
using namespace std;  
struct train  
{  
    char name[22];  
    int rp;  
    friend bool operator < (train a,train b)  
    {  
        if(a.rp==b.rp)  
        {  
            return strcmp(a.name,b.name)<0;  
        }  
        return a.rp>b.rp;//从小到大排列 队伍   
    }  
};  
train temp;  
int main()  
{  
    int n,m,p;//n辆车，m条命令  
    int i,j;  
    int num,num1,num2;  
    char str[10];  
    while(~scanf("%d%d",&n,&m))  
    {  
        priority_queue<train>q[max];  
          
        for(i=1;i<=n;++i)  
        {  
            scanf("%d",&p);  
            while(p--)  
            {  
                scanf("%s %d",temp.name,&temp.rp);  
                q[i].push(temp);  
            }  
        }  
        while(m--)  
        {  
            scanf("%s",str);  
            if(strcmp(str,"GETOUT")==0)  
            {  
                scanf("%d",&num);  
                temp=q[num].top();  
                if(!q[num].empty())//出队列之前一定要判断非空   
                {  
                    printf("%s\n",temp.name);  
                    q[num].pop();  
                }  
            }  
            else if(strcmp(str,"GETON")==0)  
            {  
                scanf("%d",&num);  
                scanf("%s %d",temp.name,&temp.rp);  
                q[num].push(temp);  
            }  
            else if(strcmp(str,"JOIN")==0)  
            {  
                scanf("%d%d",&num1,&num2);  
                while(!q[num2].empty())  
                {  
                    temp=q[num2].top();  
                    q[num2].pop();  
                    q[num1].push(temp);  
                }                 
            }  
        }         
    }  
    return 0;  
} 
/*#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct passenger{
	char name[20];
	int RP;
};
struct train{
	passenger chk[2000];
	int pt;
};
bool cmp(passenger p1,passenger p2){
	if(p1.RP!=p2.RP)
		return p1.RP>p2.RP;
	else 
		return strcmp(p1.name,p2.name)<0;
}
int main(char argc,char *argv[])
{
	int n,m,i,j,x,y;
	char order[10];
	train *t;
	while(scanf("%d %d",&n,&m)!=EOF){
		t=new train[n+1];
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			for(j=0;j<x;j++)
				scanf("%s %d",t[i].chk[j].name,&t[i].chk[j].RP);
			t[i].pt=x;
		}
		for(i=0;i<m;i++){
			scanf("%s",order);
			if(strcmp(order,"GETON")==0){
				scanf("%d",&x);
			    scanf("%s %d",t[x].chk[t[x].pt].name,&t[x].chk[t[x].pt].RP);
			    t[x].pt++;
		    }
		    else if(strcmp(order,"GETOUT")==0){
				scanf("%d",&x);
				sort((t[x].chk),(t[x].chk)+(t[x].pt),cmp);
				printf("%s\n",t[x].chk[(t[x].pt)-1].name);
				t[x].pt--;
			}
			else if(strcmp(order,"JOIN")==0){
				scanf("%d %d",&x,&y);
				for(j=0;j<t[y].pt;j++)
					t[x].chk[t[x].pt+j]=t[y].chk[j];
				t[x].pt+=t[y].pt;
				t[y].pt=0;
			}
		}
		delete []t;
	}
	return 0;
}*/