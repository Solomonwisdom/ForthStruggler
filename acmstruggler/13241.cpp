////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 08:55:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1324
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1652KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int j[1000000];
int main()
{
  int ans,z,i,m,l,t,x,k,y;
   t=1;
  while(~scanf("%d %d %d %d",&z,&i,&m,&l))
  {
    if(z==0&&i==0&&m==0&l==0)
        break;
 x=0;
    for(ans=0;;ans++)
    {
      j[ans]=l;
      l=(z*l+i)%m;
       for(k=0;k<=ans;k++)
          if(l==j[k])
          {
              y=k;
              x=1;
              break;
          }
          if(x==1)
              break;
    }
    printf("Case %d: %d\n",t++,ans-y+1);
  }
  return 0;
}/*#include<iostream>
using namespace std;
int main(void){
	int z,i,m,l,a[100000],count=0;;
	while(scanf("%d %d %d %d",&z,&i,&m,&l)){
		if(z==0&&i==0&&m==0&&l==0) break;
		a[0]=l;
		count++;
		for(int j=1,k;;j++){
			a[j]=(a[j-1]*z+i)%m;
			for(k=0;k<j;k++)
				if(a[k]==a[j]) break;
			if(k<j){ printf("case %d: %d\n",count,j-k); break;}
		}
	}
	return 0;
}*/