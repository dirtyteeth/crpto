#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <limits.h>
using namespace std;
int fast_exp(int x,int y,int mod)
{	
	int ans=1;
	while(y>0)
	{
		if((y&1)!=0)
		ans=(ans*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return ans;
		
}
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
int eu_t(int n)
{
	int res=n;
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n=n/i;
			res=res-(res/i);
		}
	}
	if(n>1)
	res=res-(res/n);
	return res;
}
int priv_key(int p1,int p2,int e)
{
	int phi = (p1-1)*(p2-1);
	int x,y;
	//int gcd=ext_euclid(e,phi);
	int d = mul_inverse(e,phi);
	return d;
}
int main()
{

	int p_key=priv_key(73,227,29);
	cout<<"Private Key: ";
	cout<<p_key<<endl;
	string s="IIT";
	cout<<"Plain Text: "<<s<<endl;
	vector<int> en;
	for(int i=0;i<s.length();i++)
	{
		int k = s[i];
		cout<<(int)s[i]<<" ";
		en.push_back(fast_exp(k,29,73*227));
	}
	cout<<endl;
	cout<<"Encryption: "<<endl;
	for(int i=0;i<en.size();i++)
	cout<<en[i]<<" ";
	cout<<endl;
	string de;
	cout<<"Decryption: "<<endl;
	for(int i=0;i<en.size();i++)
	{
		int k = en[i];
		char c1 = fast_exp(k,p_key,73*227);
		de.push_back(c1);
	}
	for(int i=0;i<de.size();i++)
	cout<<(int)de[i]<<" ";
	cout<<endl;
	cout<<de<<endl;
}