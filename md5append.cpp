#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

int main(){
cout << "Enter the message" << endl;
	string msg;
	cin >> msg;
	int padded[512];
	int len = msg.length();
	for(int i = 0; i < len; i++){
		int x = msg[i];
		for(int j = i*8 + 7; j >= i*8; j--){
			padded[j] = x%2;
			x /= 2;}}
	padded[len*8] = 1;
	for(int i = len*8; i < 496; i++) padded[i] = 0;
	int x = len*8;	
	for(int i = 511; i >= 496; i--){
		padded[i] = x%2;
		x /= 2;}
	for(int i = 0; i < 512; i+=4){
		unsigned x = padded[i]*8 + padded[i+ 1]*4 + padded[i + 2]*2 + padded[i + 3]*1;
		printf("%x",x);}
	cout << endl;
return 0;
}
