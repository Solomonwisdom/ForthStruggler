#include <cstring>
#include <cstdio>
#include <algorithm>
 
  
using namespace std;
  
int pos[101];
int ans[7205];
bool stone[7205];
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int len;
        scanf("%d",&len);
        int st,lt,m;
        scanf("%d%d%d",&st,&lt,&m);
        int ad=lt-st;
        for(int i=1;i<=m;i++){
            scanf("%d",pos+i);
        }
        sort(pos+1,pos+m+1);
        if(st==lt){
            int ans=0;
            for(int i=1;i<=m;i++){
                if(pos[i]%st==0)
                    ans++;
            }
            printf("%d\n",ans);
        } 
        else {
            int cp=st*lt,d=0,x;
            memset(ans,0x7f,sizeof(ans));
            ans[0]=0;
            memset(stone,false,sizeof(stone));
            for(int i=1;i<=m;i++){
                x=pos[i]-pos[i-1]-d;
                if(x>cp) d+=x-cp;
                pos[i]-=d;
                stone[pos[i]]=true;
            }
            for(int i=st;i<pos[m]+lt;i++){
                for(int j=st;j<=lt;j++)
                    ans[i]=min(ans[i],ans[i-j]);
                ans[i]+=stone[i];
            }
            int a=0xffff;
            for(int i=pos[m];i<pos[m]+lt;i++)
                a=min(a,ans[i]);
            printf("%d\n",a);
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1218
    User: 08143203
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:840 kb
Description

在河上有一座独木桥，TT想沿着独木桥从河的一侧到另一侧。在桥上有一些石子，TT很讨厌踩在这些石子上。由于桥的长度和TT一次移动的距离都是正整数，我们可以把独木桥上TT可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。TT从桥的起点开始，不停的向终点方向移动。一次移动的距离是S到T之间的任意正整数（包括S,T）。当TT到达或超过坐标为L的点时，就算TT到达对岸。
题目给出独木桥的长度L，TT移动的距离范围S,T，桥上石子的位置。你的任务是确定TT要想过河，最少需要踩到的石子数。

Input

第一行为T，表示T组用例。

每组输入的第一行有一个正整数L（1 <= L <= 10^9），表示独木桥的长度。第二行有三个正整数S，T，M，分别表示TT移动一次的最小距离，最大距离，及桥上石子的个数，其中1 <= S <= T <= 10，1 <= M <= 100。第三行有M个不同的正整数分别表示这M个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。

Output

每组一行，一个整数，表示最少要踩到的石子数

Sample Input
1
10
2 3 5
2 3 5 6 7
Sample Output
2
****************************************************************/