#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
const int maxn=100005;
const int maxm=10;
lolo e[maxm];
lolo pre[maxm][maxn],suf[maxm][maxn],mis[maxm][maxm];
void init() {
    e[0]=1;
    for(int i=1;i<=9;i++) e[i]=e[i-1]*10;
    for(int i=0;i<10;i++) {
        mis[i][0]=1;
        for(int j=1;j<10;j++) mis[i][j]=mis[i][j-1]*i;
    }
    for(int i=1;i<10;i++) {
        for(int j=0;j<e[5];j++) {
            int x=j;
            pre[i][j]=suf[i][j]=0;
            while(x) {
                pre[i][j]+=mis[x%10][i];
                suf[i][j]+=mis[x%10][i];
                x/=10;
            }
            pre[i][j]-=j*e[5];
            suf[i][j]-=j;
        }
        sort(pre[i],pre[i]+e[5]);
        sort(suf[i],suf[i]+e[5]);
    }
}
int main() {
    int T;
    init();
    scanf("%d",&T);
    int cas=1;
    while(T--) {
        lolo x;
        int k;
        scanf("%lld%d",&x,&k);
        lolo ans=0;
        int i=0,j=e[5]-1;
        for(;i<e[5]&&j;) {
            if(pre[k][i]+suf[k][j]>x) j--;
            else if(pre[k][i]+suf[k][j]<x) i++;
            else {
                int px=1,py=1;
                while(pre[k][++i]==pre[k][i-1]&&i<e[5]) px++;
                while(suf[k][--j]==suf[k][j+1]&&j) py++;
                ans+=1LL*px*py;
            }
        }
        if(x==0) ans--;
        printf("Case #%d: %lld\n",cas++,ans);
    }
}
