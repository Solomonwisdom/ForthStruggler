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

��һ��n*n�Ĵ󷽸񣬰��������½�ȥ����Ȼ��͵õ���һ�������δ󷽸�
������������Ҫ��б������ѡ��һЩ������Ϊ��㣬���ϻ�������ȥȾɫ��
�������ӿ���һֱȾɫֱ�������߽������Ⱦɫ�ĸ��ӡ�
��ô��������ÿ�ο���Ⱦ���������أ�
Input

�������������
��һ��Ϊ��������n��n=1000000000��,q��q=200000�����ֱ������ӳߴ��Ⱦɫ������
������q�У�ÿ�еĸ�ʽΪC R OP��C��R�ֱ������������к��У�OPΪU���������Ⱦɫ��OPΪL���������Ⱦɫ��
Output

����ÿ��Ⱦɫ�������Ⱦɫ���ӵ�������
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