#include<iostream>
#include<vector>

using namespace std;

int row(int arr[5][5], char x){
	if(x == 'j') x = 'i';
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(arr[i][j] == x){
				return i;}
		}
	}}
int col(int arr[5][5], char x){
	if(x == 'j') x = 'i';
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(arr[i][j] == x){
				return j;}
		}
	}}

int main(){
	
	int arr[5][5];
	vector<bool> list(26,true);
	list['j' - 'a'] = false;

	cout << "Enter the text" << endl;
	string text;
	cin >> text;
	cout << "Enter the key" << endl;
	string key;
	cin >> key;
	
	int ptr1 = 0, j = 0, ptr2 = 0;
	for(;j < key.length(); j++){
		if(key[j] != 'j'){ 
		arr[j/5][j%5] = key[j];
		int ind = key[j] - 'a';
		list[ind] = false;}}
	ptr1 = j;
	for(;ptr2 < 26; ptr2++){
		if(list[ptr2] == true){
			list[ptr2] = false;
			arr[ptr1/5][ptr1%5] = 'a' + ptr2;
			ptr1++; }}

	for(int i = 0; i < 5; i++){
		for(int k = 0; k < 5; k++){
			char x =  arr[i][k];
			cout << x << " ";}

	
		cout << endl;}
	int len = text.length();
	if(len%2 == 1){ 
	text += 'x'; 
	len++;}
	string encrypted = "";
	for(int i = 0; i < len; i++){
		char x = text[i];
		char y = text[i + 1];
		i++;
		if(x == y && x != 'x')
		   y = 'x';
		else if(x == y && x == 'x')
		   y = 'y';
		int rx = row(arr,x);
		int ry = row(arr,y);
		int cx = col(arr,x);
		int cy = col(arr,y);
		if(rx == ry){
		  encrypted += arr[rx][(cx + 1)%5];
		  encrypted += arr[ry][(cy + 1)%5];
		}
		else if(cx == cy){
		  encrypted += arr[(rx + 1)%5][cx];
		  encrypted += arr[(ry + 1)%5][cy];}
		else{
		  encrypted += arr[rx][cy];
		  encrypted += arr[ry][cx];
		}
	}

	cout << "Encrypted text: " << encrypted << endl;
	
	string decrypted = "";
	
	for(int i = 0; i < len; i++){
		char x = encrypted[i];
		char y = encrypted[i + 1];
		i++;
		if(x == y && x != 'x')
		   y = 'x';
		else if(x == y && x == 'x')
		   y = 'y';
		int rx = row(arr,x);
		int ry = row(arr,y);
		int cx = col(arr,x);
		int cy = col(arr,y);
		if(rx == ry){
		  decrypted += arr[rx][(cx - 1 + 5)%5];
		  decrypted += arr[ry][(cy - 1 + 5)%5];
		}
		else if(cx == cy){
		  decrypted += arr[(rx - 1 + 5)%5][cx];
		  decrypted += arr[(ry - 1 + 5)%5][cy];}
		else{
		  decrypted += arr[rx][cy];
		  decrypted += arr[ry][cx];
		}
	}
	cout << "Decrypted text: " << decrypted << endl;
return 0;
} 		
