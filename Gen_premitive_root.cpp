#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int fast_exp(int x,int y,int mod)
{	
	int ans=1;
	while(y>0)
	{
		if(y&1!=0)
		ans=(ans*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return ans;
		
}
bool check(vi &a,int p,int mod)
{
	vector<bool> flag(mod+1,false);
	set<int> st;
	for(int i=1;i<=mod;i++)
	{	
		st.insert(fast_exp(p,i,mod));
	}
	//cout<<st.size()<<endl;
	if(st.size()==mod-1)
	return true;
	else
	return false;

	
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=0;i<=n;i++)
	a[i]=i;
	vector<int> ans;
	for(int i=2;i<=n;i++)
	{
		if(check(a,i,n))
		ans.push_back(i);
	}
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<endl;
}