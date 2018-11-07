#include<bits/stdc++.h>
using namespace std;

int main(){
	string input;
	int key;
	cout << "Enter the input text" << endl;
	cin >> input;
	int len = input.length();
	for(int i = 0; i < len; i++) cout << (int)input[i] << " ";
	cout << endl;
	cout << "Enter the key" << endl;
	cin >> key;
	string encrypt = "";
	string decrypt = "";
	
	char x = (input[0] + key)%256;
	encrypt += x;
	for(int i = 1; i < len; i++){
		x = (input[i - 1] + input[i] )%256;
		encrypt += x;
	}
	cout << "The encrypted text:" << endl;
	cout << encrypt << endl;
	for(int i = 0; i < len; i++) cout << +(u_int8_t)encrypt[i] << " ";
	cout << endl;
	cout << "The decrypted text:" << endl;
	x = (encrypt[0] - key + 256)%256;
	decrypt += x;
	for(int i = 1; i < len; i++){
		x = (encrypt[i] - decrypt[i - 1] + 256)%256;
		decrypt += x;
	}
	cout << decrypt << endl;
return 0;
}
