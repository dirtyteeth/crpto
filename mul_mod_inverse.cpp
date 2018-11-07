#include<iostream>
using namespace std;

int extended_euclid(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;}
	else{
		int x1,y1;
		int gcd = extended_euclid(b%a,a,&x1,&y1);
		
		*x = y1 - (b/a)*x1;
		*y = x1;

		return gcd;
	}
}

int main(){
	cout << "Enter the number and the modulo" << endl;
	int num, mod;
	cin >> num >> mod;
	
	int mod_inv,y,gcd;
	gcd = extended_euclid(num, mod,&mod_inv, &y);
	mod_inv = (mod_inv + mod)%mod;
	if(gcd != 1) 
		cout << "Multiplicative inverse doesn't exist" << endl;
	else
		cout << "The multiplicative inverse is: " << mod_inv << endl;
return 0;
} 	 
	
