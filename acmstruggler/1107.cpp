////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 08:59:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<stdio.h>
typedef struct wulin
{
    char peo;
    int i,j,a,b,c,d;
}WULIN;
void fight(WULIN wl[],int f);
void next(WULIN wl[],int f);
int main()
{
    int k,n,nx,f,sums,sumw,sume,nums,numw,nume;
    WULIN wl[1010];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&nx);
        for(f=1,k=1;;k++,f++)
        {
            scanf(" %c",&wl[k].peo);
            if(wl[k].peo=='0')
                break;
            scanf("%d%d%d%d%d",&wl[k].i,&wl[k].j,&wl[k].a,&wl[k].b,&wl[k].c);
            wl[k].d=1;
        }
        while(nx--)
        {
            fight(wl,f);
            next(wl,f);
        }
        for(sums=0,sumw=0,sume=0,nums=0,numw=0,nume=0,k=1;k<f;k++)
        {
            if(wl[k].peo=='S')
            {
                sums++;
                nums+=wl[k].c;
            }
            if(wl[k].peo=='W')
            {
                sumw++;
                numw+=wl[k].c;
            }
            if(wl[k].peo=='E')
            {
                sume++;
                nume+=wl[k].c;
            }
        }
        printf("%d %d\n",sums,nums);
        printf("%d %d\n",sumw,numw);
        printf("%d %d\n",sume,nume);
        printf("***\n");
    }
    return 0;
}
void next(WULIN wl[],int f)
{
    int k;
    for(k=1;k<f;k++)
    {
        if(wl[k].peo=='S')
        {
            if(wl[k].i==12 && wl[k].d==1 || wl[k].i==1 && wl[k].d==-1)
                wl[k].d=-wl[k].d;
            wl[k].i+=wl[k].d;
        }
        if(wl[k].peo=='W')
        {
            if(wl[k].j==12 && wl[k].d==1 || wl[k].j==1 && wl[k].d==-1)
                wl[k].d=-wl[k].d;
            wl[k].j+=wl[k].d;
        }
        if(wl[k].peo=='E')
        {
            if(wl[k].i==12 && wl[k].d==1 || wl[k].i==1 && wl[k].d==-1
               || wl[k].j==12 && wl[k].d==1 || wl[k].j==1 && wl[k].d==-1)
                wl[k].d=-wl[k].d;
            if(wl[k].i==12 && wl[k].j==1 || wl[k].i==1 && wl[k].j==12)
                wl[k].d=0;
            wl[k].i+=wl[k].d;
            wl[k].j+=wl[k].d;
        }
    }
}
void fight(WULIN wl[],int f)
{
    int i,j,k,ks,kw,ke,sf,wf,ef;
    for(i=1;i<13;i++)
        for(j=1;j<13;j++)
        {
            for(sf=0,wf=0,ef=0,ks=0,kw=0,ke=0,k=1;k<f;k++)
            {
                if(wl[k].i==i && wl[k].j==j && wl[k].peo=='S')
                {
                    sf++;
                    ks=k;
                }
                if(wl[k].i==i && wl[k].j==j && wl[k].peo=='W')
                {
                    wf++;
                    kw=k;
                }
                if(wl[k].i==i && wl[k].j==j && wl[k].peo=='E')
                {
                    ef++;
                    ke=k;
                }
            }
            if(2==sf+wf+ef && sf!=2 && wf!=2 && ef!=2)
            {
                sf=(wl[ks].a*0.5+wl[ks].b*0.5)*(wl[ks].c+10)/100;
                wf=(wl[kw].a*0.8+wl[kw].b*0.2)*(wl[kw].c+10)/100;
                ef=(wl[ke].a*0.2+wl[ke].b*0.8)*(wl[ke].c+10)/100;
                if(wl[ks].peo!='0' && wl[kw].peo!='0')
                {
                    wl[ks].c-=wf;
                    wl[kw].c-=sf;
                }
                else if(wl[kw].peo!='0' && wl[ke].peo!='0')
                {
                    wl[kw].c-=ef;
                    wl[ke].c-=wf;
                }
                else if(wl[ks].peo!='0' && wl[ke].peo!='0')
                {
                    wl[ks].c-=ef;
                    wl[ke].c-=sf;
                }
                if(wl[ks].c<1)
                    wl[ks].peo='0';
                if(wl[kw].c<1)
                    wl[kw].peo='0';
                if(wl[ke].c<1)
                    wl[ke].peo='0';
            }
        }
}