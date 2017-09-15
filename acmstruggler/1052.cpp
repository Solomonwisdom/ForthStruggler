////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 19:26:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
/*nƥ���n�α�����������̹��ڸ��ӣ�Ϊ�˼򻯹��̣����ǿ��԰�������̷ָ�ɺܶ�׶�*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j;
    int tj[1100],tjwin;//��ɵ������ʤ�ľ��� 
    int king[1100],kingwin;//�����������ʤ�ľ��� 
    int tjfast,tjslow,kingslow,kingfast;//�ֱ��¼ÿ���׶���ɺ͹�������������������� 
    while(scanf("%d",&n)&&(n!=0))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&tj[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&king[i]);
        }
        sort(tj,tj+n);//����ƥ�ٶ��������� 
        sort(king,king+n);
        tjwin=kingwin=0; 
        tjfast=kingfast=n-1;tjslow=kingslow=0;//��¼����������� 
        /*ÿ������ɸý׶���������͹��������������
        ���������
        һ�������ȹ����죬��Ӯ,������ƥ��ıȽ�  ���Ӯ 
        ���������ȹ��������͹����������䣬���������Ĺ��������������������������� ����� 
        ����һ���죬�Ƚ�������
                   ����ɿ���ȹ����Ŀ죬ֱ�ӱ��� ���Ӯ    
                   ���������������������� ˼�뻹�����Ĺ��������� �����*/
         for(i=0;i<n;i++)
         {
             if(tj[tjslow]>king[kingslow])
             {
                 tjwin++;//���ʤ 
                 tjslow++;kingslow++;//������һ�׶�����Ƚ� 
             }
             else if(tj[tjslow]<king[kingslow])
             {
                 kingwin++;
                 tjslow++;kingfast--;//���������������˹��������� 
             }
             else
             {
                 if(tj[tjfast]>king[kingfast])
                 {
                     tjwin++;
                     tjfast--;kingfast--;//������һ�׶�����Ƚ� 
                 }
                 else 
                 {
                     if(tj[tjslow]<king[kingfast])//ֻ�������������ڹ��������� ������Ӯ �ڶ����������......���ΰ� 
                     {
                          kingwin++;
                          tjslow++;kingfast--;//���Ĺ��������� 
                     }
                 } 
             } 
         }
         printf("%d\n",200*(tjwin-kingwin));
    }
    return 0;
}