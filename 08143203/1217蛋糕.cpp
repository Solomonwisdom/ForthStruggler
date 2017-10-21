#include <cstdio>
#include <algorithm>
#include <cstring>
   
using namespace std;
   
int boards[51];
int temp[51];
int rails[1050];
int maxv[51];
int n, m;
int sum1, sum2;
int L[1050], R[1050];
   
bool dfs(int dep, int cur)
{
    if (R[0] == 0)
        return true;
    if (cur == n + 1)
        return false;
    for (int i = L[0]; i != 0; i = L[i]) {
        if (R[i] == 0 || rails[R[i]] != rails[i]) {
            if (cur != 1 && boards[cur] == boards[cur - 1]) {
                if (maxv[cur - 1] < rails[i]) {
                    continue;
                }
            }
            if (temp[cur] >= rails[i]) {
                temp[cur] -= rails[i];
                R[L[i]] = R[i];
                L[R[i]] = L[i];
                bool flag = false;
                if (R[0] != 0) {
                    if (temp[cur] < rails[R[0]]) {
                        sum1 -= temp[cur];
                        flag = true;
                        if (sum1 < sum2) {
                            sum1 += temp[cur];
                            temp[cur] += rails[i];
                            R[L[i]] = i;
                            L[R[i]] = i;
                            continue;
                        }
                        bool ret = dfs(dep, cur + 1);
                        sum1 += temp[cur];
                        temp[cur] += rails[i];
                        R[L[i]] = i;
                        L[R[i]] = i;
                        if (ret)
                            return true;
                        continue;
                    }
                }
                int save = maxv[cur];
                if (maxv[cur] < rails[i])
                    maxv[cur] = rails[i];
                //printf("%d %d\n", cur, rails[i]);
                bool ret = dfs(dep, cur);
                if (flag) {
                    sum1 += temp[cur];
                }
                maxv[cur] = save;
                R[L[i]] = i;
                L[R[i]] = i;
                temp[cur] += rails[i];
                if (ret)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    scanf("%d", &n);
    sum1 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &boards[i]);
        sum1 += boards[i];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &rails[i]);
    }
    sort(rails + 1, rails + m + 1);
    sort(boards + 1, boards + n + 1);
    for (int i = 1; i <= n; i++)
        temp[i] = boards[i];
    memset(maxv, 0, sizeof(maxv));
   
    int l = 0, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        sum2 = 0;
        for (int i = 1; i <= mid; i++) {
            sum2 += rails[i];
        }
        for (int i = 1; i <= mid; i++) {
            L[i] = i - 1;
        }
        L[0] = mid;
        for (int i = 0; i < mid; i++) {
            R[i] = i + 1;
        }
        R[mid] = 0;
        if (sum1 >= sum2 && rails[mid] <= boards[n] && dfs(mid, 1)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", r);
    }
    return 0;
}
/**************************************************************
    Problem: 1217
    User: 08143203
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:820 kb
Description

TT��������n�鵰�⣬���ϱ�ѧ���Ƿ����ˣ�ֻ�ü����з�Orz��ÿ����Ҫ������������ͬ~~TT�аѵ��������е��⣬�������ܰ����鵰��ƴ�������������ֲ�����κ������鵰�⡣�������㣬TTr�����е��⣬�������������ˡ�

Input

һ��T������

ÿ���һ��Ϊn��TT��n�����⡣������n�У�ÿ�б�ʾһ������Ĵ�С����һ��һ����m��Ϊ�༶��������Ȼ��m�У�ÿ��һ������Ϊһ����θ�ڵĴ�С��(1<=n<=50, 1<=m<=1024)

Output

ÿ��һ�У���������˼����ˡ�

Sample Input
1
4
30
40
50
25
10
15
16
17
18
19
20
21
25
24
30
Sample Output
7
****************************************************************/