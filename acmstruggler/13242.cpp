////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 09:12:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1324
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:2004KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
    int z,i,m,l,a[100000],count=0;;
    while(scanf("%d %d %d %d",&z,&i,&m,&l)){
        if(z==0&&i==0&&m==0&&l==0) break;
        count++;
        for(int j=0,k;;j++){
            a[j]=l;
			l=(l*z+i)%m;
            for(k=0;k<=j;k++)
                if(a[k]==l) break;
            if(k<=j){ printf("Case %d: %d\n",count,j+1-k); break;}
        }
    }
    return 0;
}