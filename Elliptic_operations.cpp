#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int> 
using namespace std;
int ext_euclid(int a,int b,int &x,int &y)
{
	if(a==0)
	{
		x=0;
		y=1;
		return b;
	}
	int x1,y1;
	int g=ext_euclid(b%a,a,x1,y1);
	y=x1;
	x=y1-(b/a)*x1;
	return g;
}

int mul_inverse(int a,int m)
{
	int x, y;
	int g=ext_euclid(a,m,x,y);
	if(g!=1)
	return -1;
	else
	{
		int res = (x%m + m)%m;
		return res;
	}
}
bool same(pii p,pii q)
{
		if(p.first==q.first && p.second==q.second)
		return true;
		else
		return false;
}
int cal_slope(pii p,pii q,int a,int n)
{
	if(same(p,q))
	{
		int num = (3*(p.first*p.first) + a)%n;
		int den = mul_inverse(2*p.second,n);
		int slope = (n+(num*den))%n;
		return slope;
	}
	else
	{
		int num = q.second-p.second;
		//if((q.first-p.first)==0)
		//cout<<p.first<<" "<<q.first<<" "<<p.second<<" "<<q.second<<endl;
		int den = mul_inverse((q.first-p.first),n);
		int slope = (n+(num*den))%n;
		return slope;
	}
}
pii add(pii p,pii q,int n,int a)
{
	int sl = cal_slope(p,q,a,n);
	//cout<<sl<<endl;
	int x = (n + ((int)pow(sl,2) - p.first - q.first))%n;
	int y = (n + (sl*(p.first-x) - p.second))%n;
	pii ans;
	ans.first=(x+n)%n;
	ans.second=(n+y)%n;
	return ans;
}
int main()
{
	pii p,q;
	p.first=14;
	p.second=28;
	q.first=15;
	q.second=16;
	pii ans = add(p,q,29,1);
	cout<<"Sum of the two point"<<endl;
	cout<<ans.first<<" "<<ans.second<<endl;
	pii temp;
	pii a;
	a.first=24;
	a.second=10;
	temp=a;
	for(int i=0;i<10;i++)
	{
		 if(temp.first==a.first && temp.second!=a.second)
		 {
			 temp=a;
			 i+=2;
		 }
		 else
		 temp=add(temp,a,29,1);
	}
	cout<<"Product of points"<<endl;
	cout<<temp.first<<" "<<temp.second<<endl;

}