////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 10:08:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1308
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const char *weekdays[] =
{
	"Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};
const char *monthname[] =
{
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};
const int daycount[] =
{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
int calendar(int mouth,int day,int year)
{
	int count,century,leap;
	if(year<=0 || mouth>12 || mouth<1 || day >31 || day<1)
		return -1;
	if((mouth==4||mouth==6||mouth==9||mouth==11)&&(day>30||day<1))
		return -1;
	if(year<=1752){
		if(year==1752&&mouth==9&&day>2&&day<14)
			return -1;
		if(year%4==0){
			leap=1;
			if(mouth==2&&day>29){ return -1;}}
		else
			{
				leap=0;
				if(mouth==2&&day>28) return -1;
			}
		count=(year-1)*365+(year-1)/4;
		if(leap&&mouth>2) count++;
		count+=daycount[mouth-1]+day;
		if(year==1752){
			if(mouth>9||(mouth==9&&day>=14))
				count-=11;}
		return (count+5)%7;
	}
	else{
		if((year%4==0&&year%100!=0)||year%400==0){
			leap=1;
			if(mouth==2&&day>29) return -1;}
		else {
			leap=0;
			if(mouth==2&&day>28) return -1;}
		count=((year-1)*365+(year-1)/4);
		century=(year-1)/100-17;
		count+=(daycount[mouth-1]+day);
		count-=(11+century);
		count+=(century+1)/4;
		if(leap&&mouth>2) count++;
		return (count+5)%7;
	}
}
int main(void){
	int mou,d,y,w;
	while(cin>>mou>>d>>y&&mou&&d&&y){
		w=calendar(mou,d,y);
		if(w==-1) {
			printf("%d/%d/%d is an invalid date.\n",mou,d,y);
			continue;}
		else printf("%s %d, %d is a %s\n",monthname[mou-1],d,y,weekdays[w]);
	}
	return 0;
}