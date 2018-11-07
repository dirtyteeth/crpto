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
	cout << "Enter The string to be encrypted" << endl;
	string str;
	getline(cin,str);
	cout << "Enter the key1, key2" << endl;
	int key1, key2;
	cin >> key1>>key2;
	
	string encrypted = "";
	int len = str.length();
	for(int i = 0; i < len; i++){
		char x = str[i];
		if(x == ' ')
			encrypted += " ";
		else
			encrypted += ((x - 'a')*key1 + key2)%26 + 'a';
	}
	int inv_key,temp;
	extended_euclid(key1,26,&inv_key,&temp);
	inv_key = (inv_key + 26)%26; 
	string decrypted = "";
	for(int i = 0; i < len; i++){
		char x = encrypted[i];
		if(x == ' ')
			decrypted += " ";
		else{
			int tem = (x - 'a' - key2 + 26)%26;
			decrypted += tem*inv_key%26 + 'a';}
	}

	cout << "Encrypted Text: " << encrypted << endl;
	cout << "Decrypted Text: " << decrypted << endl;

return 0;
}			 
