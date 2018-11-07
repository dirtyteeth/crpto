#include<iostream>
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
int phi(int n) 
{ 
    int result = n; 
    for (int p = 2; p * p <= n; ++p) { 
        if (n % p == 0) { 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 