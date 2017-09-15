////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 20:03:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1443
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[14];
int main()
{
    int k;
    a[1]=2;
    for(int i=2; i<14; i++)
    {
        for(int m=i+1;; m++)
        {
            int s=0,j=2*i;
            while(1)
            {
                int x=(s+m)%j;
                if(!x)
                    x=j;
                if(x<=i)
                    break;
                s=x-1;
                j--;
                if(j==i)
                {
                    a[i]=m;
                    break;
                }
            }
            if(j==i)
                break;
        }
    }
    while(cin>>k&&k)
        cout<<a[k]<<endl;
    return 0;
}/*#include<stdio.h>
#include<stdlib.h>
typedef struct link_node{
	char data;
	struct link_node *next;
}node;
long long n,t,u,g,sum,k,j,i,w,m;
int main()
{
	
	node *p,*q,*head,*pre;
    while(scanf("%I64d",&n)!=EOF)
    {	  
			    if(n==0)
			    {
			    	break;
			    }
       	 	  head=(node*)malloc(sizeof(node));
       	 	  head->data='G';
       	 	  p=head;
       	 	  i=1;
       	 	  while(i<2*n)
       	 	  {
       	 	  	 q=(node*)malloc(sizeof(node));
       	 	  	 if(i<n)
       	 	  	 {
       	 	  	 	q->data='G';
       	 	  	 }
       	 	  	 else
       	 	  	 {
       	 	  	 	q->data='B';
       	 	  	 }
       	 	  	 p->next=q;
       	 	  	 p=q;
       	 	  	 i++;
       	 	  }
       	 	  p->next=head;
 	     t=1;
 	      while(1>0)
 	      {  
 	        m=t;
 	      	p=head;
                   u=0;
                   j=1;
                   g=0;
                   while(u!=n)
                   {
                         if(j==m)
                         {
                               if(p->data=='X')
                               {
                                     p=p->next;
                               }
                               else
                               {
                               	     if(p->data=='G')
                               	     {
                               	     	g=1;
                               	     	break;
                               	     }
                               	     else
                               	     {
                               	     p->data='X';
                                     p=p->next; 
                                     j=1;
                                     u++;
                               	     }              
                               }
                         }
                         else
                         {
                         	   if(p->data=='X')
                         	   {
                         	   	  p=p->next;
                         	   }
                         	   else
                         	   {
                         	   	  p=p->next;
                         	   	  j++;
                         	   }                   
                         }                    
                   }                      
                               if(g==0)
                               {
                               	 break;
                               }
                   p=head;
                   i=1;
               while(i<=2*n)
               {
               	  if(i<=n)
       	 	  	 {
       	 	  	 	p->data='G';
       	 	  	 }
       	 	  	 else
       	 	  	 {
       	 	  	 	p->data='B';
       	 	  	 }
                               	  p=p->next;
                               	  i++;
                               }
                               t++;
	       	 	      }  	           
                       printf("%I64d\n",m);  	 
    }  
}*/