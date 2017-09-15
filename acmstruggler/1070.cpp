////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 21:04:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int main(){
    int T;
    cin>> T;
    while( T-- ){
        int  n, percost = INF, vol = 0;
        string s, ans;
        cin >> n;
        while(n--){
            int cost, p, day = 0;
            cin >> s >> cost >> p;
            if(p < 200) continue;
            day = p / 200;
            if(day > 5) day = 5;
            if( cost/day < percost ||(cost/day == percost && p > vol) ){
                ans = s;
                percost = cost/day;
                vol = p;
            }
        }
        cout<<ans<<endl;
    }
}
/*#include<iostream>
using namespace std;
int main(void)
{
    int n,k,i,j,p,v,id,*vol;
    double *cost,temp;
    char **name;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        name=new char*[k];
        cost=new double[k];
        vol=new int[k];
        for(j=0;j<k;j++){
            name[j]=new char[101];
            cin>>name[j];
            cin>>p;
            cin>>vol[j];
            if(vol[j]<200){ cost[j]=0;}
            else {v=(vol[j]/200>5)?5:vol[j]/200;
            cost[j]=double(p)/v;}
        }
        for(j=0;j<k;j++)
            if(!cost[j]){ temp=cost[j];id=j;}
        for(;j<k;j++){
            if(cost[j]<temp&&cost[j]){
                temp=cost[j];id=j;v=vol[j];}
            if(cost[j]==temp&&vol[j]>v){
                id=j;v=vol[j];}
        }
        if(j!=k)
            cout<<name[id]<<endl;
        else cout<<endl;
        delete []name;
        delete []cost;
        delete []vol;
    }
    return 0;
}*/