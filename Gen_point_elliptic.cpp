#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int> 
using namespace std;
vector<pii> gen_point(int a,int b,int p)
{
	vector<pii> ans;
	for(int i=0;i<p;i++)
	{
		int k = ((int)pow(i,3)+ (a*i) + b)%p;
		for(int j=0;j<p;j++)
		{
			if(((int)pow(j,2)%p)==k)
			{
				pii pt;
				pt.first=i;
				pt.second=j;
				ans.push_back(pt);
				if(j!=0)
				{
					pt.second=p-j;
					ans.push_back(pt);
				}
			}
		}
	}
	return ans; 
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
int main()
{
	int a,b,p;
	cin>>a>>b>>p;
	vector<pii> ans=gen_point(a,b,p);
	set<pii> st;
	for(int i=0;i<ans.size();i++)
	{
		if(st.find(ans[i])==st.end())
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
		st.insert(ans[i]);
	}
}
