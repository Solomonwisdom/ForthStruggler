题意：一辆卡车要行驶L单位距离。最开始时，卡车上有P单位汽油，每向前行驶1单位距离消耗1单位汽油。如果在途中车上的汽油耗尽，卡车就无法继续前行，即无法到达终点。途中共有N个加油站，加油站提供的油量有限，卡车的油箱无限大，无论加多少油都没问题。给出每个加油站距离终点的距离和能够提供的油量，问卡车从起点到终点至少要加几次油？如果不能到达终点，输出-1。 
分析：由于N比较大，应该找一个高效的解法。稍微转换一下思考方式：在卡车开往终点的途中，只有在加油站才可以加油。但是，如果认为“在到达加油站i时，就获得了一次在之后的任何时候都可以加Bi单位汽油的权利”，在解决问题上也是一样的。而在之后需要加油时，就认为是在之前经过的加油站加的油就可以了。因为希望加油次数尽可能少，所以当燃料为0了之后再加油是最好的选择。基于贪心的思想，当燃料为0时，选择能加油量最大的加油站。所以可以用一个优先队列来保存经过的加油站的油量，当需要加油时，取出队列中的最大元素即可。 
code:
//
//  main.cpp
//  basic
//
//  Created by 汪浩港 on 2017/2/25.
//
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)

using namespace std;

typedef long long lolo;
const int maxn = 1e4+5;
struct node
{
    int dist,fuel;
}stop[maxn];
bool cmp(node a,node b)
{
    return a.dist>b.dist;
}
int main(void)
{
    int n,l,p,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d %d",&stop[i].dist,&stop[i].fuel);
        stop[n].dist=stop[n].fuel=0;
        n++;
        scanf("%d %d",&l,&p);
        sort(stop, stop+n, cmp);
        ans=0;
        priority_queue<int, vector<int>, less<int> > Q;
        for(int i=0;i<n;i++)
        {
            int req = l - stop[i].dist;
            while(p<req)
            {
                if(Q.empty())
                {
                    ans=-1;
                    break;
                }
                p+=Q.top();
                Q.pop();
                ans++;
            }
            if(ans==-1) break;
            p-=req;
            l=stop[i].dist;
            Q.push(stop[i].fuel);
        }
        printf("%d\n", ans);
    }
}

