////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 13:15:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
# include<stdio.h>
# include<string.h>
int main()
{
	int a[410],b[410],c[410],d[410],flag2;
	int i,j,k,len1,len2;
	char s1[410],s2[410];
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		len1=strlen(s1);
		flag2=1;
		for(i=0;s1[i];i++)//�ж��Ƿ���С���㣨1��
			if(s1[i]=='.')
				break;
		k=0;
		for(j=i-1;j>=0;j--) //���������֣�2��
			a[k++]=s1[j]-'0';
		k=0;                    //��С�����֣����Ѹ�λ��Ϊ��b[0](3)
		b[k++]=0;
		if(i<len1-1)
			for(j=i+1;s1[j];j++)
				b[k++]=s1[j]-'0';
		len2=strlen(s2);
		for(i=0;s2[i];i++)//����ͬ��1��
			if(s2[i]=='.')
				break;
		k=0;
		for(j=i-1;j>=0;j--)  //����ͬ��2��
			c[k++]=s2[j]-'0';
		k=0;          
		d[k++]=0;   //����ͬ��3��
		if(i<len2-1)
			for(j=i+1;s2[j];j++)
				d[k++]=s2[j]-'0';
		for(i=0;i<410;i++)//����������ӣ���a��
		{
			a[i]+=c[i];
			if(a[i]>=10)
			{
				a[i+1]++;
				a[i]-=10;
			}
		}
		for(i=409;i>=1;i--)//С��������ӣ���b��
		{
			b[i]+=d[i];
			if(b[i]>=10)
			{
				b[i-1]++;
				b[i]-=10;
			}
		}
		a[0]+=b[0];
		/**********����Ϊ���Ӳ���***********/
		for(i=0;i<410;i++)
			if(a[i]>=10)
			{
				a[i+1]++;
				a[i]-=10;
			}
		/**********����Ϊ���Ӳ���**********/
		i=409;
		while(a[i]==0&&i>=0)
			i--;
		//printf("%d",a[i--]);
		while(i>=0)
		{
			printf("%d",a[i]);
			i--;
		}
		i=409;
		while(b[i]==0&&i>=1)
			i--;
		if(i==0)//�ж�С�������Ƿ�ȫΪ0
			flag2=0;
		if(flag2==0)   //����ǣ������
			printf("\n");
		else if(flag2==1)  //�������С������
		{
			printf(".");
			for(j=1;j<=i;j++)
				printf("%d",b[j]);
			printf("\n");
		}
	}
	return 0;
}