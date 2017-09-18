/*struct BigInteger{
	static const int base=100000000;
	static const int width=8;
	vector<int> s;
	BigInteger(){}
	BigInteger(long long num=0){*this=num;}
	BigInteger operator=(long long num){
		s.clear();
		do{
			s.push_back(num%base);
			num/=base;
		}while(num>0);
		return *this;
	}
	BigInteger operator=(const string& str){
		s.clear();
		int x,len=(str.length()-1)/width+1;
		for(int i=0;i<len;i++){
			int end=str.length()-i*width;
			int start=max(0,end-width);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	BigInteger operator+(const BigInteger& b) const{
		BigInteger c;
		c.s.clear();
		for(int i=0,g=0;;i++){
			if(g==0&&i>=s.size()&&i>=b.s.size()) break;
			int x=g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x%base);
			g=x/base;
		}
		return c;
	}
	BigInteger operator+(const int& b) const{
		BigInteger c=*this;
		int g=b;
		for(int i=0;g&&i<s.size();i++){
			g+=s[i];
			c.s[i]=g%base;
			g/=base;
		}
		if(g){
			c.s.push_back(g);
		}
		return c;
	}
	BigInteger operator-(const int& b) const{
		BigInteger c=*this;
		int g=b;
		for(int i=0;g&&i<s.size();i++){
			c.s[i]-=g;
			if(c.s[i]<0){
				c.s[i]+=base;
				g=1;
			}
		}
		return c;
	}
	BigInteger operator+=(const BigInteger& b){
		*this=*this+b;return *this;
	}
	bool operator<(const BigInteger& b) const{
		if(s.size()!=b.s.size()) return s.size()<b.s.size();
		int i=s.size()-1;
		while(i>=0&&s[i]==b.s[i]) i--;
		if(i) return s[i]<b.s[i];
		return false;
	}
	BigInteger operator*(const int& b){
		BigInteger t=*this;
		int jin=0;
		for(int i=0;i<s.size();i++){
			t.s[i]=jin+t.s[i]+jin;
			jin=t.s[i]/base;
			t.s[i]%=base;
		}
		while(jin){
			t.s.push_back(jin%base);
			jin/=base;
		}
		return t;
	}
};*/

/*#include <iostream>    //1159 multiple of bigInteger
#include<cstdio>
#include<string>
using namespace std;
int main(void){
    int *a,*b,*c,i,j,n,t;
    string m1,m2;
    scanf("%d",&n);
    while(n--){
        cin>>m1>>m2;
        a=new int[m1.size()];
        b=new int[m2.size()];
        c=new int[m1.size()+m2.size()];
        for(i=0;i<m1.size();i++)
            if(isdigit(m1[m1.size()-1-i]))
                a[i]=m1[m1.size()-1-i]-48;
            else a[i]=0;
        for(i=0;i<m2.size();i++)
            if(isdigit(m2[m2.size()-1-i]))
                b[i]=m2[m2.size()-1-i]-48;
            else b[i]=0;
        if(m1[0]=='0'||m2[0]=='0')
            printf("0\n");
        else{
            for(i=0;i<m1.size()+m2.size();i++)
                c[i]=0;
            int k;
            for(i=0;i<m2.size();i++){
                for(j=0;j<m1.size();j++){
                    k=m1.size()+m2.size()-1;
                    c[k-i-j]+=b[i]*a[j];
                    t=c[k-i-j];
                    while(t>9){
                        c[k-i-j]=t%10;
                        c[k-i-j-1]+=t/10;
                        t=c[k-i-j-1];
                        k--;
                    }
                }
            }
            for(i=0;i<m1.size()+m2.size();i++)
                if(c[i]!=0) break;
            if(m1[0]=='-'&&m2[0]!='-')
                printf("-");
            else if(m1[0]!='-'&&m2[0]=='-')
                printf("-");
            else printf("+");
            for(int k=i;k<m1.size()+m2.size();k++)
                cout<<c[k];
            cout<<endl;
        }
    }
    return 0;
}*/
