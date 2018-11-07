#include<bits/stdc++.h>
#define vi vector<ll>
#define ll long long 
using namespace std;

ll gcd(ll a,ll b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
ll fast_exp(ll x,ll y,ll mod)
{	
	ll ans=1;
	while(y>0)
	{
		if(y&1!=0)
		ans=(ans*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return ans;
		
}
bool check(vi &a,ll p,ll mod)
{
	vector<bool> flag(mod+1,false);
	set<ll> st;
	for(ll i=1;i<=mod;i++)
	{	
		st.insert(fast_exp(p,i,mod));
	}
	//cout<<st.size()<<endl;
	if(st.size()==mod-1)
	return true;
	else
	return false;

	
}
ll ext_euclid(ll a,ll b,ll &x,ll &y)
{
	if(a==0)
	{
		x=0;
		y=1;
		return b;
	}
	ll x1,y1;
	ll g=ext_euclid(b%a,a,x1,y1);
	y=x1;
	x=y1-(b/a)*x1;
	return g;
}

ll mul_inverse(ll a,ll m)
{
	ll x, y;
	ll g=ext_euclid(a,m,x,y);
	if(g!=1)
	return -1;
	else
	{
		ll res = (x%m + m)%m;
		return res;
	}
}
int main()
{
	ll p=3119;ll e1=2;ll d=127;ll r=307;
	ll M=320;
	ll e2=fast_exp(e1,d,p);
	ll S1=fast_exp(e1,r,p);
	ll inv_r = mul_inverse(r,p-1);
	//cout<<inv_r<<endl;
	//cout<<(M-d*S1 + 10000*p-10000)*inv_r<<endl;
	ll S2=(((M-d*S1 + 10000*p-10000)%(p-1))*inv_r)%(p-1);
	ll v2=((fast_exp(e2,S1,p)%p)*(fast_exp(S1,S2,p)%p))%p;
	ll v1=fast_exp(e1,M,p);
	cout<<"e2: "<<e2<<"\n"<<"S1: "<<S1<<"\n"<<"S2:"<<S2<<endl;
	cout<<v1<<" "<<v2<<endl;
	if(v1==v2)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}