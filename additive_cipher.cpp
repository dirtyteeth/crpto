#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	cout << "Enter The string to be encrypted" << endl;
	string str;
	getline(cin,str);
	cout << "Enter the key" << endl;
	int key;
	cin >> key;
	
	string encrypted = "";
	int len = str.length();
	for(int i = 0; i < len; i++){
		char x = str[i];
		if(x == ' ')
			encrypted += " ";
		else
			encrypted += (x - 'a' + key)%26 + 'a';
	}
	string decrypted = "";
	for(int i = 0; i < len; i++){
		char x = encrypted[i];
		if(x == ' ')
			decrypted += " ";
		else
			decrypted += (x - 'a' - key + 26)%26 + 'a';
	}

	cout << "Encrypted Text: " << encrypted << endl;
	cout << "Decrypted Text: " << decrypted << endl;

return 0;
}			 
