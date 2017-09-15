////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 18:53:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void){
	char **map,str[201];
	int col,len,row;
	while(cin>>col&&col){
		cin>>str;
		len=strlen(str);
		row=len/col;
		map=new char*[row];
		for(int i=0;i<row;i++) map[i]=new char[col];
		for(int i=0,k=0;i<row;i++)
		{
			if(i%2==0)
				for(int j=0;j<col;j++)
					map[i][j]=str[k++];
			else
				for(int j=col-1;j>=0;j--)
					map[i][j]=str[k++];
			/*if(j%2==0)map[j][k++]=str[i++];
			else map[j][k--]=str[i++];
			if(k==(col-1)&&j%2==0){
				map[j++][k]=str[i++];
				map[j][k--]=str[i++];}
			if(k==0&&j%2==1){
				map[j++][k]=str[i++];
				map[j][k++]=str[i++];
			}*/
		}
		for(int i=0,j=0;;)
		{
			cout<<map[i++][j];
			if(i==row){i=0;j++;}
			if(i==0&&j==col) break;
		}
		cout<<endl;
	}
	return 0;
}