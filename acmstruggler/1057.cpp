////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-24 09:38:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1057
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
char op[4]={'.','!','X','#'};
int main(void)
{
    int t,n,dish[20][20],d[16],temp[20][20];
	int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<16;i++)
			scanf("%d",&d[i]);
		for(i=0;i<20;i++)
			for(j=0;j<20;j++){
				scanf("%d",&dish[i][j]);
				temp[i][j]=dish[i][j];
			}
		while(n--){
			for(i=0;i<20;i++){
				for(j=0;j<20;j++){
					k=dish[i][j];
					if(i!=0) k+=temp[i-1][j];
					if(i!=19) k+=temp[i+1][j];
					if(j!=0) k+=temp[i][j-1];
					if(j!=19) k+=temp[i][j+1];
					dish[i][j]+=d[k];
					if(dish[i][j]>3) dish[i][j]=3;
					if(dish[i][j]<0) dish[i][j]=0;
				}
			}
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
					temp[i][j]=dish[i][j];
		}
		for(i=0;i<20;i++){
			for(j=0;j<20;j++)
				printf("%c",op[dish[i][j]]);
			printf("\n");
		}
		if(t) printf("\n");
	}
    return 0;
}