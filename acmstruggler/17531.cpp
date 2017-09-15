////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 14:05:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[410],s2[410];
    int a[410],b[410],c[410],d[410];
    int i,j,k,len1,len2,s,t,num1,num2;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        for(i=0;i<=409;i++)
        {
            a[i]=0;
            b[i]=0;
            c[i]=0;
            d[i]=0;
        }
        s=len1=strlen(s1);
        t=len2=strlen(s2);
        for(i=0;i<len1;i++)
            if(s1[i]=='.')
            {
                s=i;
                break;
            }
            for(i=0;i<len2;i++)
                if(s2[i]=='.')
                {
                    t=i;
                    break;
                }
                k=0;
                for(j=s-1;j>=0;j--)
                    a[k++]=s1[j]-'0';
                k=0;
                for(j=t-1;j>=0;j--)
                    b[k++]=s2[j]-'0';
                k=1;
                if(s+1<len1)
                    for(j=s+1;j<=len1-1;j++)
                        c[k++]=s1[j]-'0';
                    k=1;
                    if(t+1<len2)
                        for(j=t+1;j<=len2-1;j++)
                            d[k++]=s2[j]-'0';
                        num1=len1-s>len2-t?len1-s:len2-t;
                        for(i=num1;i>=1;i--)
                        {
                            c[i]+=d[i];
                            if(c[i]>=10)
                            {
                                c[i]-=10;
                                c[i-1]++;
                            }
                        }
                        num2=s-1>t-1?s-1:t-1;
                        a[0]+=c[0];
                        for(i=0;i<=num2;i++)
                        {
                            a[i]+=b[i];
                            if(a[i]>=10)
                            {
                                a[i]-=10;
                                a[i+1]++;
                            }
                        }
                        if(a[num2+1]>0)
                            printf("%d",a[num2+1]);
                        for(i=num2;i>=0;i--)
                            printf("%d",a[i]);        
                        for(i=num1;i>=1;i--)
                        {
                            if(c[i]==0)
                                continue;
                            else
                                break;
                        }
                        if(i==0)
                            ;
                        else
                        {
                            printf(".");
                            for(j=1;j<=i;j++)
                                printf("%d",c[j]);
                        }
                        printf("\n");
    }
    return 0;
}