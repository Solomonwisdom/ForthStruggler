////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 10:14:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1107
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <list>
#include <set>
#include <cmath>
using namespace std;
// 1107
class DiZi
{
public:
	int m_neiLi, m_wuYi, m_shengMing;
	char m_type;
	int x, y;
	int moveDirX, moveDirY;
	list<DiZi*> (*m_wuLinShiJie)[12][12];

	DiZi() : m_wuLinShiJie(NULL)
	{

	}

	virtual double getGongJiLi() = 0;
	virtual void calcStep() = 0;
	void move()
	{
		list<DiZi*> &old = (*m_wuLinShiJie)[x][y];
		for (list<DiZi*>::iterator iter = old.begin(); iter != old.end(); ++iter)
		{
			if (*iter == this)
			{
				old.erase(iter);
				break;
			}
		}
		
		calcStep();
		(*m_wuLinShiJie)[x][y].push_back(this);
	}
};

class ShaoLin : public DiZi
{
public:
	ShaoLin()
	{
		moveDirX = 1;
		moveDirY = 0;
	}
	virtual double getGongJiLi()
	{
		return floor((0.5 * m_neiLi + 0.5 * m_wuYi) * (m_shengMing + 10) / 100);
	}
	virtual void calcStep()
	{
		if (moveDirX > 0)
		{
			if (x == 11)
				moveDirX = -1;
			x += moveDirX;
		}
		else if (moveDirX < 0)
		{
			if (x == 0)
				moveDirX = 1;
			x += moveDirX;
		}
	}
};

class WuDang : public DiZi
{
public:
	WuDang()
	{
		moveDirX = 0;
		moveDirY = 1;
	}
	virtual double getGongJiLi()
	{
		return floor((0.8 * m_neiLi + 0.2 * m_wuYi) * (m_shengMing + 10) / 100);
	}
	virtual void calcStep()
	{
		if (moveDirY > 0)
		{
			if (y == 11)
				moveDirY = -1;
			y += moveDirY;
		}
		else if (moveDirY < 0)
		{
			if (y == 0)
				moveDirY = 1;
			y += moveDirY;
		}
	}
};

class EMei : public DiZi
{
public:
	EMei()
	{
		moveDirX = 1;
		moveDirY = 1;
	}
	virtual double getGongJiLi()
	{
		return floor((0.2 * m_neiLi + 0.8 * m_wuYi) * (m_shengMing + 10) / 100);
	}
	virtual void calcStep()
	{
		if ((x == 0 && y == 11) || (x == 11 && y == 0))
			return;

		if (moveDirX > 0)
		{
			if (x == 11)
			{
				moveDirX = -1;
				moveDirY = -moveDirY;
			}
			else if (moveDirY > 0 && y == 11)
			{
				moveDirX = -moveDirX;
				moveDirY = -moveDirY;
			}
			else if (moveDirY < 0 && y == 0)
			{
				moveDirX = -moveDirX;
				moveDirY = -moveDirY;
			}
			x += moveDirX;
			y += moveDirY;
		}
		else if (moveDirX < 0)
		{
			if (x == 0)
			{
				moveDirX = 1;
				moveDirY = -moveDirY;
			}
			else if (moveDirY > 0 && y == 11)
			{
				moveDirX = -moveDirX;
				moveDirY = -moveDirY;
			}
			else if (moveDirY < 0 && y == 0)
			{
				moveDirX = -moveDirX;
				moveDirY = -moveDirY;
			}
			x += moveDirX;
			y += moveDirY;
		}
	}
};

void main()
{
	int n = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			list<DiZi*> wuLinShiJie[12][12];
			set<DiZi*> diZiSet;
			int step = 0;
			cin >> step;
			char type;
			while (cin >> type)
			{
				if (type == '0')
					break;
				DiZi *d = NULL;
				switch (type)
				{
				case 'S':
					d = new ShaoLin;
					break;
				case 'W':
					d = new WuDang;
					break;
				case 'E':
					d = new EMei;
					break;
				}

				d->m_type = type;
				cin >> d->x >> d->y >> d->m_neiLi >> d->m_wuYi >> d->m_shengMing;
				d->m_wuLinShiJie = &wuLinShiJie;
				--d->x;
				--d->y;
				wuLinShiJie[d->x][d->y].push_back(d);
				diZiSet.insert(d);
			}

			for (int j = 0; j < step; ++j)
			{
				for (int a = 0; a < 12; ++a)
				{
					for (int b = 0; b < 12; ++b)
					{
						list<DiZi*> &l = wuLinShiJie[a][b];
						if (l.size() != 2)
							continue;
						if (l.front()->m_type == l.back()->m_type)
							continue;
						int fg = (int)l.front()->getGongJiLi();
						int bg = (int)l.back()->getGongJiLi();
						l.front()->m_shengMing -= bg;
						l.back()->m_shengMing -= fg;
						if (l.front()->m_shengMing <= 0)
						{
							diZiSet.erase(l.front());
							delete l.front();
							l.pop_front();
						}
						if (l.back()->m_shengMing <= 0)
						{
							diZiSet.erase(l.back());
							delete l.back();
							l.pop_back();
						}
					}
				}

				for (set<DiZi*>::iterator iter = diZiSet.begin(); iter != diZiSet.end(); ++iter)
				{
					DiZi *d = *iter;
					d->move();
				}
			}

			int sc = 0, wc = 0, ec = 0;
			int ss = 0, ws = 0, es = 0;

			for (set<DiZi*>::iterator iter = diZiSet.begin(); iter != diZiSet.end(); ++iter)
			{
				DiZi *d = *iter;
				if (d->m_type == 'S')
				{
					++sc;
					ss += d->m_shengMing;
				}
				else if (d->m_type == 'W')
				{
					++wc;
					ws += d->m_shengMing;
				}
				else if (d->m_type == 'E')
				{
					++ec;
					es += d->m_shengMing;
				}
				delete d;
			}

			cout << sc << ' ' << ss << endl;
			cout << wc << ' ' << ws << endl;
			cout << ec << ' ' << es << endl;
			printf("***\n");
		}
	}
}/*
#include<iostream>
using namespace std;
struct wulin{
	int neili,wuyi,hp;
	int x,y,dir;
	char pai;
};
void move(wulin a[],int n){
	for(int k=1;k<n;k++){
		if(a[k].pai=='S'){
			if((a[k].y==12&&a[k].dir==1)||(a[k].y==1&&a[k].dir==-1))
				a[k].dir=-a[k].dir;
			a[k].x+=a[k].dir;
		}
		else if(a[k].pai=='W'){
			if((a[k].x==12&&a[k].dir==1)||(a[k].x==1&&a[k].dir==-1))
				a[k].dir=-a[k].dir;
			a[k].y+=a[k].dir;
		}
		else if(a[k].pai=='E'){
			if((a[k].x==12&&a[k].y==1)||(a[k].x==1&&a[k].y==12))
				a[k].dir==0;
			else if((a[k].x==12&&a[k].dir==1)||(a[k].y==12&&a[k].dir==1)||(a[k].x==1&&a[k].dir==-1)||(a[k].x==12&&a[k].dir==1))
				a[k].dir=-a[k].dir;
			a[k].x+=a[k].dir;
			a[k].y+=a[k].dir;
		}
	}
}
void fight(wulin a[],int n){
	int sl,wd,em,k,ps,pw,pe;
	int ws,es,ss;
	for(int i=1;i<13;i++)
		for(int j=1;j<13;j++){
			for(sl=wd=em=ps=pw=pe=0,k=1;k<n;k++)
			{
				if(a[k].x==i&&a[k].y==j)
					if(a[k].pai=='S'){
						sl++;
						ps=k;
					}
					else if(a[k].pai=='W'){
						wd++;
						pw=k;
					}
					else if(a[k].pai=='E'){
						em++;
						pe=k;
					}
			}
			if(em+wd+sl==2&&em!=2&&wd!=2&&em!=2){
				if(sl) ss=(double(a[ps].neili)*0.5+double(a[ps].wuyi)*0.5)*(a[ps].hp+10)/100;
				if(wd) ws=(double(a[pw].neili)*0.8+double(a[pw].wuyi)*0.2)*(a[pw].hp+10)/100;
				if(em) es=(double(a[pe].neili)*0.2+double(a[pe].wuyi)*0.8)*(a[pe].hp+10)/100;
				if(sl&&wd&&a[ps].pai!='0'&&a[pw].pai!='0'){
					a[ps].hp-=ws;
					if(a[ps].hp<=0) a[ps].pai='0';
					a[pw].hp-=ss;
					if(a[pw].hp<=0) a[pw].pai='0';
				}
				else if(sl&&em&&a[ps].pai!='0'&&a[pe].pai!='0')
				{
					a[ps].hp-=es;
					if(a[ps].hp<=0) a[ps].pai='0';
					a[pe].hp-=ss;
					if(a[pe].hp<=0) a[pe].pai='0';
				}
				else if(wd&&em&&a[pw].pai!='0'&&a[pe].pai!='0')
				{
					a[pw].hp-=es;
					if(a[pw].hp<=0) a[pw].pai='0';
					a[pe].hp-=ws;
					if(a[pe].hp<=0) a[pe].pai='0';
				}
			}
		}
}
int main(void){
	int t,step,n;
	wulin zd[1001];
	scanf(" %d",&t);
	while(t--){
		scanf("%d",&step);
		for(n=1;;n++){
			cin>>zd[n].pai;
			if(zd[n].pai=='0') break;
			else scanf("%d %d %d %d %d",&zd[n].x,&zd[n].y,&zd[n].neili,&zd[n].wuyi,&zd[n].hp);
			zd[n].dir=1;
		}
		while(step--){
			fight(zd,n);
			move(zd,n);
		}
		int sums=0,sumw=0,sume=0,hs=0,hw=0,he=0;
		for(int i=1;i<n;i++)
			switch(zd[i].pai){
			case'S':
				sums++;
				hs+=zd[i].hp;
				break;
			case'W':
				sumw++;
				hw+=zd[i].hp;
				break;
			case'E':
				sume++;
				he+=zd[i].hp;
				break;
		}
		printf("%d %d\n",sums,hs);
		printf("%d %d\n",sumw,hw);
		printf("%d %d\n",sume,he);
		printf("***\n");
	}
	return 0;
}*/