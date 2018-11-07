#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << "Enter the message without space" << endl;
	string input;
	cin >> input;
	int len_inp = input.length();
	cout << "ASCII:" << endl;
	for(int i = 0; i < len_inp; i++) cout << (int)input[i] << " ";
	cout << endl;
	cout << "Enter the key" << endl;
	string key;
	cin >> key;
	int len_key = key.length();
	cout << "ASCII:" << endl;
	for(int i = 0; i < len_key; i++) cout << (int)key[i] << " ";
	cout << endl;
	string encrypt = "";
	for(int i = 0; i < len_inp; i++){
		int x = key.at(i%len_key);
		char y = (input.at(i) + x)%256;
		encrypt += y;
	}
	cout << "The encrypted messsage:" << endl;
	cout << encrypt << endl;
	cout << "Ascii:" << endl;
	for(int i = 0; i < len_inp; i++) cout << +(u_int8_t)encrypt[i] << " ";
	cout << endl;
return 0;
}	
