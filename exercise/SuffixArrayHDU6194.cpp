#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cctype>
#include <map>
#include <set>
#include <cmath>

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)

using namespace std;

typedef long long lolo;
typedef pair<int, int> pii;

const int maxn = 2000005;
const int INF = 0x3f3f3f3f;
const lolo inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

inline void read(int &x) {
    x=0;
    char c;
    do {
        c= getchar();
    } while (c<'0'||c>'9');
    do {
        x = x*10+c-'0';
        c= getchar();
    } while (c>='0'&&c<='9');
}

int s[maxn],Log2[maxn];
int sa[maxn],c[maxn],t[maxn],t2[maxn];
void build_sa(int m,int n) {
    int i,*x=t,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=s[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(i=n-k;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=0;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void init(int n) {
    for(int i = 0; i <=n; i ++)Log2[i] = (i == 0 ? -1 : Log2[i >> 1] + 1);
}
int Rank[maxn],height[maxn];
void getHeight(int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) Rank[sa[i]]=i;
    for(i=0;i<n;i++) {
        if(k) k--;
        j=sa[Rank[i]-1];
        while(s[j+k]==s[i+k]) k++;
        height[Rank[i]]=k;
    }
}
int n,d[maxn][30];
void RMQ_init(int nn) {
    for(int i=1;i<=nn;i++) d[i][0]=height[i];
    for(int j=1;(1<<j)<=nn;j++)
        for(int i=1;i+(1<<j)-1<=nn;i++)
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R) {
    int k=Log2[R-L+1];
    return min(d[L][k],d[R-(1<<k)+1][k]);
}
int LCP(int a,int b) {
    return RMQ(a, b);
}

char expr[maxn];
int k;
int main() {
    int T;
    read(T);
    while(T--) {
        read(k);
        scanf("%s",expr);
        n=(int)strlen(expr);
        for(int i=0;i<n;i++) s[i]=expr[i]-'a'+1; s[n]=0;
        build_sa(28,n+1);
        getHeight(n);
        height[n+1]=0;
        init(n);
        RMQ_init(n);
        lolo ans = 0;
        if(k==1) {
            for(int i=1;i<=n;i++)
                ans += max(n-sa[i]-max(height[i],height[i+1]),0);
        }
        else
            for(int i=1;i<=n-k+1;i++)
                ans+=max(0,LCP(i+1,i+k-1)-max(height[i],height[i+k]));
        printf("%lld\n", ans);
    }
    return 0;
}
/*题意：给出一个字符串，问其中出现k次的子串的个数有多少个*/