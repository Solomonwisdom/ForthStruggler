////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 20:21:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1218
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int row,col,n,**grap,p;
	char str[20],s;
	while(cin>>str){
		if(strcmp(str,"ENDOFINPUT")==0) break;
		if(strcmp(str,"START")==0){
			cin>>row>>col;
			grap=new int*[row];
			for(int i=0;i<row;i++) grap[i]=new int[col];
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++){
					cin>>s;
					grap[i][j]=s-'0';
				}
			for(int i=0;i<row-1;i++){
				for(int j=0;j<col-1;j++){
					p=(grap[i][j]+grap[i+1][j]+grap[i][j+1]+grap[i+1][j+1])/4;
					printf("%d",p);
				}
				printf("\n");
			}
		}
		if(strcmp(str,"END")==0) continue;
	}
	return 0;
}