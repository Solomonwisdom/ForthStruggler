#include <cstdio>
#include <fstream>
#include <cstring>
#include <map>
#include <functional>
using namespace std;
  
int main(){
    int n,q;
    int r,c;
    char op;
    scanf("%d %d",&n,&q);
    map<int,int,greater<int> > fisr;
    map<int,int,greater<int> > fisc;
    map<int,int,greater<int> >::iterator it;
    while(q--){
        scanf("%d %d %c",&c,&r,&op);
        if(fisr.find(r)!=fisr.end()||fisc.find(c)!=fisc.end()){
            printf("0\n");
            continue;
        }
        if(op=='L'){
            it=fisc.upper_bound(c);
            if(it==fisc.end()){
                printf("%d\n",c);
                fisr.insert(map<int,int,greater<int> >::value_type(r,0));
            }
            else{
                for(;it!=fisc.end();it++){
                    if(it->second<r) break;
                }
                if(it==fisc.end()){
                    printf("%d\n",c);
                    fisr.insert(map<int,int,greater<int> >::value_type(r,0));
                }
                else{
                    printf("%d\n",c-it->first);
                    fisr.insert(map<int,int,greater<int> >::value_type(r,it->first-1));
                }
            }
        }
        else{
            it=fisr.upper_bound(r);
            if(it==fisr.end()){
                printf("%d\n",r);
                fisc.insert(map<int,int,greater<int> >::value_type(c,0));
            }
            else{
                for(;it!=fisr.end();it++){
                    if(it->second<c) break;
                }
                if(it==fisr.end()){
                    printf("%d\n",r);
                    fisc.insert(map<int,int,greater<int> >::value_type(c,0));
                }
                else{
                    printf("%d\n",r-it->first);
                    fisc.insert(map<int,int,greater<int> >::value_type(c,it->first-1));
                }
            }
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1209
    User: 08143203
    Language: C++
    Result: Accepted
    Time:316 ms
    Memory:1732 kb
Description

有一个n*n的大方格，把它的右下角去掉，然后就得到了一个三角形大方格。
现在萌萌妹子要从斜角线上选择一些格子作为起点，向上或者向左去染色。
萌萌妹子可以一直染色直到遇到边界或者已染色的格子。
那么萌萌妹子每次可以染几个格子呢？
Input

单组测试用例。
第一行为两个整数n（n=1000000000）,q（q=200000），分别代表格子尺寸和染色次数。
接下来q行，每行的格式为C R OP，C和R分别代表起点所在列和行，OP为U则代表向上染色，OP为L则代表向左染色。
Output

对于每次染色，输出被染色格子的数量。
Sample Input
5 3
1 5 U
5 1 L
2 4 U
Sample Output
5
4
3
****************************************************************/