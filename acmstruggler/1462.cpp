////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 08:46:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1462
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	string w1,w2,w3,w4;
	int i,j,p1,p2,k,m;
	bool flag=true;
	while(cin>>w1&&w1!="#"){
		cin>>w2>>w3>>w4;
		if(flag) flag=false;
		else cout<<endl;
		for(i=0;i<w1.size();i++)
			if((p1=w2.find_first_of(w1[i]))!=string::npos) break;
		if(i==w1.size()) {
			printf("Unable to make two crosses\n");
			continue;
		}
		for(j=0;j<w3.size();j++)
			if((p2=w4.find_first_of(w3[j]))!=string::npos) break;
		if(j==w3.size()){
			printf("Unable to make two crosses\n");
			continue;
		}
		m=0;
		if(p1>=p2){
			for(k=0;k<w2.size();k++){
				if(k<p1-p2)cout<<setw(i+1)<<w2[k]<<endl;
			    else if(k==p1){
					m++;
					cout<<w1<<"   "<<w3<<endl;
				}
			    else if(k>=p1-p2){
					cout<<setw(i+1)<<w2[k];
					if(m<w4.size()) cout<<setw(j+3+w1.size()-i)<<w4[m++];
					cout<<endl;
				}
			}
			while(m<w4.size()) cout<<setw(w1.size()+4+j)<<w4[m++]<<endl;
		}
		else {
			for(k=0;k<w4.size();k++){
				if(k<p2-p1) cout<<setw(w1.size()+4+j)<<w4[k]<<endl;
				else if(k==p2){
					m++;       
					cout<<w1<<"   "<<w3<<endl;
				}
				else if(k>=p2-p1){
					if(m<w2.size())cout<<setw(i+1)<<w2[m++]<<setw(j+3+w1.size()-i)<<w4[k]<<endl;
					else cout<<setw(w1.size()+4+j)<<w4[k]<<endl;
				}
			}
			while(m<w2.size()) cout<<setw(i+1)<<w2[m++]<<endl;
		}
	}
	return 0;
}