#include<bits/stdc++.h>
#define N 2
using namespace std;
string MOD;
string dp[N][N],idp[N][N],C[N][N];
string stuffZero(string s,int n)
{	while(s.length()<n)
		s='0'+s;
	return s;
}
int binaryToInt(string s)
{	int ans=0;	
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++)
		ans+=(1<<i)*(s[i]-'0');
	return ans;
}
string intToBinary(int num)
{	string ans="";
	while(num)
	{	char c=num%2;
		ans+=(c+'0');
		num/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int len(int n){
	int m=0;
	while(n){
		n=n/2;
		m++;
	}
	return m;
}
string divide(string m,string MOD) {
	int mod=binaryToInt(MOD),n=binaryToInt(m);
	while(len(n)>=len(mod)){
		n=n^(mod<<(len(n)-len(mod)));
	}
	return intToBinary(n);
}
string add( string s, string p ) {
	int n=binaryToInt(s),m=binaryToInt(p);
	return divide(intToBinary(n^m), MOD);
}
string mul( string s, string p){
	int n = binaryToInt(s),m = binaryToInt(p),ans=0;
	for(int i=0;(1<<i)<=n;i++){
		if(n&(1<<i))
			ans=ans^(m<<i);
	}
	return divide(intToBinary(ans), MOD);
}
void matrixMul(string A[N][N],string B[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		C[i][j]="0";
			for(int k=0;k<N;k++)
				C[i][j]=add(C[i][j],mul(A[i][k],B[k][j]));
}	}	}
int main() {
	int t,c;
	string s,p;
	cout<<"\nEnter the number of test cases: ";
	cin>>t;
	cout<<"Irreducible poly in binary form: ";
	cin>>MOD;
	while(t--){
	cout<<"\n\nEnter <1 to Add> <2 to multiply> <3 for inverse>: ";
	cin>>c;
		switch(c){
			case 1:{
				cout<<"\n** ADDITION **\nEnter the two numbers in binary form: ";
				cin>>s>>p;
				cout<<"ADDITION OF THE POLYNOMIALS : "<<stuffZero(add(s,p),2*N)<<endl;
				break;
			}	
			case 2:{
				cout<<"\n** MULTIPLICATION **\nEnter the two numbers in binary form: ";
				cin>>s>>p;
				cout<<"MULTIPLICATION OF THE POLYNOMIALS : "<<stuffZero(mul(s,p),2*N);
				break;		
			}
			case 3:{
				cout<<"\n** INVERSE OF A MATRIX **\nEnter the matrix :\n";
				for(int i=0;i<N;i++)
					for(int j=0;j<N;j++)
						cin>>dp[i][j];
				string det=add(mul(dp[0][0],dp[1][1]),mul(dp[0][1],dp[1][0]));
				cout<<"INVERSE MATRIX: \n";
				idp[0][0]=divide(dp[1][1],det);
				idp[0][1]=divide(dp[1][0],det);
				idp[1][0]=divide(dp[0][1],det);
				idp[1][1]=divide(dp[0][0],det);
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++)
						cout<<stuffZero(idp[i][j],2*N)<<" ";
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
