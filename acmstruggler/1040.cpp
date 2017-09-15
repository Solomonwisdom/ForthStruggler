////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-30 10:05:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
	int pivot=low,i=low,j=high;
	int mark=arr[pivot];
	while(i<j){
		while(i<j&&arr[j]>=mark)
			j--;
		arr[i]=arr[j];
		while(i<j&&arr[i]<=mark)
			i++;
		arr[j]=arr[i];
	}
	arr[i]=mark;
	return i;
}
void qicksort(int arr[],int low,int high){
	if(low<high){
		int mid=partition(arr,low,high);
		qicksort(arr,low,mid-1);
		qicksort(arr,mid+1,high);
	}
}
int main(char argc,char *argv[])
{
	int t,n,*arr;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		qicksort(arr,0,n-1);
		for(int i=0;i<n-1;i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}