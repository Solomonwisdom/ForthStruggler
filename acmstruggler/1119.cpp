////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 12:56:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1119
////Problem Title: 
////Run result: Accept
////Run time:608MS
////Run memory:1884KB
//////////////////System Comment End//////////////////
#include <cstdio>   
#include <string>   
using namespace std;   
char oper;   
char num1[510],num2[510];   
char str[1100],ans[510][510];   
int len[510],len1,len2;   
   
void strTonum()   
{   
    int i=0,j;   
       
    while(str[i])   
        i++;   
    j=1;i--;   
    while(str[i]>='0' && str[i]<='9')   
    {   
        num2[j]=str[i]-'0';   
        i--;j++;   
    }   
    len2=j-1;   
    oper=str[i];    i--;   
    j=1;   
    while(i>=0 && str[i]>='0' && str[i]<='9')   
    {   
        num1[j]=str[i]-'0';   
        i--;j++;   
    }   
    len1=j-1;   
}   
int sub()   
{   
    int i,j,dec;   
    i=1;dec=0;   
    for(i=1;i<=len2;i++)   
    {   
        ans[0][i]=num1[i]-num2[i]+dec;   
        dec=0;   
        if(ans[0][i]<0)   
        {   ans[0][i]+=10;  dec=-1;}   
    }   
    for(  ; i<=len1;i++)   
    {   
        ans[0][i]=num1[i]+dec;   
        dec=0;   
        if(ans[0][i]<0)   
        {   ans[0][i]+=10;  dec=-1;}   
    }   
    while(ans[0][ i-1 ]==0 && i>0)   
        i--;   
    if(i==0)   
        len[0]=1;   
    else   
        len[0]=i-1;   
    return len[0];   
}   
int add()   
{   
    int i,j,inc;   
    inc=0;   
    for(i=1;i<=len2;i++)   
    {   
        ans[0][i]=num1[i]+num2[i]+inc;   
        inc=0;   
        if(ans[0][i]>9)   
        {   ans[0][i]-=10;  inc=1;}   
    }   
    for( ; i<=len1;i++)   
    {   
        ans[0][i]=num1[i]+inc;   
        inc=0;   
        if(ans[0][i]>9)   
        {   ans[0][i]-=10;  inc=1;}   
    }   
    if(inc>0)   
    {   
        ans[0][i]=inc;   
        i++;   
    }   
    len[0]=i-1;   
    return len[0];   
}   
int multiple()   
{   
    int i,j,k,inc,llen,t;   
       
    for(i=1;i<=len2;i++)   
    {   
        if(num2[i]==0)   
        {   
            ans[i-1][i]=0;   
            len[i-1]=i;   
        }   
        else   
        {   
            j=1;inc=0;   
            for(k=1;k<i;k++)   
                ans[i-1][k]=0;   
            for(j=1;j<=len1;j++,k++)   
            {   
                ans[i-1][k]=num2[i]*num1[j]+inc;   
                inc=0;   
                if(ans[i-1][k]>9)   
                {   inc=ans[i-1][k]/10; ans[i-1][k]%=10;}   
            }   
            if(inc>0)   
            {   
                ans[i-1][k]=inc;   
                j++;k++;   
            }   
            len[i-1]=k-1;   
        }   
    }//while *   
    //+   
    llen=i-2;j=1;inc=0;   
    for(j=1;j<=len[llen];j++)   
    {   
        for(i=0,t=0 ;i<=llen; i++)   
            t+=ans[i][j];   
        t+=inc;   
        ans[llen+1][j]=t%10;   
        inc=0;   
        if(t>9)   
            inc=t/10;   
    }   
    while(inc>0)   
    {   
        ans[llen+1][j]=inc%10;   
        j++;   
        inc/=10;   
    }   
    len[llen+1]=j-1;   
    return j-1;   
}   
int main()   
{   
    int i,j,n,x,y,llen,t;   
       
       
    scanf("%d",&n);   
    while( n-- )   
    {   
        memset(ans,0,sizeof(ans));   
        memset(num1,0,sizeof(num1));   
        memset(num2,0,sizeof(num2));   
        scanf("%s",str);   
        strTonum();   
        switch(oper)   
        {   
        case '+':   
            llen=add();   
            break;   
        case '-':   
            llen=sub();   
            break;   
        case '*':   
            llen=multiple();   
            break;   
        }   
           
        //////////////////////   
        llen= llen > len1 ? llen : len1;   
        llen= llen > len2+1 ? llen : len2+1;   
           
        for(i=0; i< llen-len1  ;i++)//×¢Òâ·ûºÅÎ»    
            printf(" ");   
        for(i=len1;i>=1;i--)   
            printf("%c",num1[i]+'0');   
        printf("\n");   
        for(i=0; i< llen-len2-1  ;i++)   
            printf(" ");   
        printf("%c",oper);   
        for(i=len2;i>=1;i--)   
            printf("%c",num2[i]+'0');   
        printf("\n");   
               
        //////////////////////   
        //for(i=0;i<len2;i++)   
            //printf("%d\n",len[0]);   
        t= len[0] > len2+1 ? len[0] : len2+1;   
        for(i=llen-t;i>0;i--)   
            printf(" ");   
        for(i=0; i<t  ;i++)   
            printf("-");   
        printf("\n");   
                   
        switch(oper)   
        {   
        case '+':   
        case '-':   
            if(llen>len[0])   
                for(i=llen-len[0];i>0;i--)   
                    printf(" ");   
            for(i=len[0];i>=1;i--)   
                printf("%c",ans[0][i]+'0');   
            printf("\n");   
            break;   
        case '*':   
            for(i=0;i<len2;i++)   
            {   
                for(j=0;j<llen-len[i];j++)   
                    printf(" ");   
                for(j=len[i];j>i;j--)   
                    printf("%c",ans[i][j]+'0');   
                printf("\n");   
            }   
            if(len2>1)   
            {   
                for(i=0; i<llen-len[len2]  ;i++)   
                    printf(" ");   
                for(   ; i<llen ;i++)   
                    printf("-");   
                printf("\n");   
                j=len2;   
                for(i=llen;i>len[j];i--)   
                    printf(" ");   
                for(i=len[j];i>=1;i--)   
                    printf("%c",ans[j][i]+'0');   
                printf("\n");   
            }   
            break;   
        }   
        printf("\n");   
    }//while   
    return 0;   
}   