////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 16:00:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1119
////Problem Title: 
////Run result: Accept
////Run time:624MS
////Run memory:1880KB
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
/*#include<iostream>
#include<string.h>
using namespace std;
int a[501],b[501],res[501][501];
int len[510],len1,len2;
void add(){
	int i,jia=0;
	for(i=0;i<len1||i<len2;i++){
		res[0][i]=jia+a[i]+b[i];
		jia=res[0][i]/10;
		res[0][i]%=10;
	}
	if(jia) res[0][i++]=jia;
	len[0]=i;
}
void sub(){
	int i;
	for(i=0;i<len1;i++){
		res[0][i]=a[i]-b[i];
		if(res[0][i]<0){
			res[0][i]+=10;
			res[0][i+1]--;
		}
	}
	while(res[0][i]==0&&i>=0) i--;
	if(i<0) len[0]=1;
	else len[0]=i+1;
}
void multiple(){
	int i,j,k,jia=0;
	for(i=0;i<len2;i++){
		if(b[i]==0){ res[i][i]=0;len[i]=i+1;}
		else{
		for(j=0;j<i;j++)
			res[i][j]==0;
		for(k=0,jia=0;k<len1;j++,k++){
			res[i][j]=a[k]*b[i]+jia;
			jia=res[i][j]/10;
			res[i][j]%=10;
		}
		while(jia){
			res[i][j]=jia;
			jia=res[i][j]/10;
			res[i][j++]%=10;
		}
		len[i]=j;
	}
	}
	for(i=0;i<len[len2-1];i++){
		res[len2][i]=jia;
		for(j=0;j<len2;j++)
			res[len2][i]+=res[j][i];
		jia=res[len2][i]/10;
		res[len2][i]%=10;
	}
	while(jia){
		res[len2][i]=jia;
		jia=res[len2][i]/10;
		res[len2][i++]%=10;
	}
	len[len2]=i;
}
int main(void){
	char exp[1010],oper;
	int t,i,j,ak,bk,llen;
	scanf("%d",&t);
	while(t--){
		memset(res,0,sizeof(res));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(len,0,sizeof(len));
		cin>>exp;
		i=0;
		while(isdigit(exp[i]))i++;
		oper=exp[i];
		for(j=i-1,ak=0;j>=0;j--,ak++)
			a[ak]=exp[j]-'0';
		len1=ak;
		for(j=strlen(exp)-1,bk=0;j>i;j--,bk++)
			b[bk]=exp[j]-'0';
		len2=bk;
		switch(oper){
		case'+':
			add();
			llen=len[0];
			break;
		case'-':
			sub();
			llen=len[0];
			break;
		case'*':
			multiple();
			llen=len[len2];
			break;
		}
		llen=llen>len1?llen:len1;
		llen=llen>len2+1?llen:len2+1;
		for(i=0;i<llen-len1;i++)
			printf(" ");
		for(i=len1-1;i>=0;i--)
			printf("%d",a[i]);
		printf("\n");
		for(i=0;i<llen-len2-1;i++)
			printf(" ");
		printf("%c",oper);
		for(i=len2-1;i>=0;i--)
			printf("%d",b[i]);
		printf("\n");
		int t=len[0]>len2+1?len[0]:len2+1;
		for(i=llen-t;i>0;i--)   
            printf(" ");   
        for(i=0; i<t;i++)   
            printf("-");   
        printf("\n"); 
		switch(oper){
		case'+':
		case'-':
			if(llen>len[0])
				for(i=0;i<llen-len[0];i++)
					printf(" ");
			for(i=len[0]-1;i>=0;i--)
				printf("%d",res[0][i]);
			printf("\n");
			break;
		case'*':
			for(i=0;i<len2;i++){
				for(j=0;j<llen-len[i];j++)
					printf(" ");
				for(j=len[i]-1;j>=i;j--)
					printf("%d",res[i][j]);
				printf("\n");
			}
			if(len2>1)   
            {   
                for(i=0; i<llen-len[len2]  ;i++)   
                    printf(" ");   
                for(   ; i<llen ;i++)   
                    printf("-");   
                printf("\n");     
                for(i=llen;i>len[len2];i--)   
                    printf(" ");   
                for(i=len[len2]-1;i>=0;i--)   
                    printf("%d",res[len2][i]);   
                printf("\n");   
            }   
            break;   
        }   
        printf("\n");   
    }//while   
	return 0;
}*/