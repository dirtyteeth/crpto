#include<iostream>
#include<string>
using namespace std;

int main(){
	cout << "Enter the length of encryption key" << endl;
	int len; cin >> len;
	int key[len];
	int dec_key[len];
	cout << "Enter the key" << endl; 
	for(int i = 0; i < len; i++) cin >> key[i];
	
	for(int i = 0; i < len; i++) dec_key[key[i] - 1] = i + 1;

	cout << "The decryption key:" << endl;
	for(int i = 0; i < len; i++) cout << dec_key[i] << " ";
	cout << endl;
return 0;
} 
