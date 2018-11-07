#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << "Enter the input text without space" << endl;
	string input; cin >> input;
	int len = input.length();
	cout << "ASCII:" << endl;
	for(int i = 0; i < len; i++) cout << (int)input[i] << " ";
	cout << endl;
	cout << "Enter the key stream" << endl;
	int key[len];
	for(int i = 0; i < len; i++) cin >> key[i];
	
	string encrypt = "";
	for(int i = 0; i < len;i++){
		char x = (key[i] + input[i])%256;
		encrypt += x;
	}
	cout << "The encrypted message:" << endl;
	cout << encrypt << endl;
	for(int i = 0; i < len; i++) cout << +(u_int8_t)encrypt[i] << " ";
	cout << endl;
	
	cout << "Enter the required decrypted text" << endl;
	string required;
	cin >> required;	
	int dec_key[len];
	for(int i = 0; i < len; i++){
		int x = required[i] - encrypt[i];
		if(x >= 0)
			dec_key[i] = x;
		else
			dec_key[i] = x + 256;
	}
	cout << "Required decryption key:" << endl;
	for(int i = 0; i < len; i++) cout << dec_key[i] << " ";
	cout << endl;
return 0;
}
