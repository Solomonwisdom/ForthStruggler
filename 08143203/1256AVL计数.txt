#include <cstdio>
#include <cstring>
const int mod=(1e9)+7;
int mini[12],maxi[12];
long long dp[105][12];
int cs[3][2]={-2,-1,-1,-1,-1,-2};
int main() {
    memset(dp,0,sizeof(dp));
    int n;
    mini[1]=1;mini[2]=2;
    maxi[1]=1;maxi[2]=3;
    for(int i=3;i<12;i++){
        maxi[i]=(maxi[i-1]<<1)+1;
        mini[i]=mini[i-1]+mini[i-2]+1;
    }
    dp[1][1]=1;dp[2][2]=2;dp[3][2]=1;
    for(int i=4;i<101;i++){
        for(int j=2;j<12;j++) {
            if(i>maxi[j]) continue;
            if(i>=mini[j]){
                for(int k=0;k<3;k++){
                    int ni=j+cs[k][0],nj=j+cs[k][1];
                    for(int ii=mini[ni];ii<=maxi[ni]&&i-ii-1>=1;ii++) {
                        if(i-ii-1>=1&&i-ii-1>=mini[nj]&&i-ii-1<=maxi[nj])
                            dp[i][j]=(dp[i][j]+dp[ii][ni]*dp[i-ii-1][nj]%mod)%mod;
                    }
                }
            }
        }
    }
    while(scanf("%d",&n)==1) {
        long long ans=0;
        for(int i=0;i<12;i++)
            ans=(dp[n][i]+ans)%mod;
        printf("%lld\n",ans);
    } 
    return 0;
}
/**************************************************************
    Problem: 1256
    User: 08143203
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:816 kb
****************************************************************/