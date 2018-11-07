#include<bits/stdc++.h>
using namespace std;

string dec_to_binary(int num){
	string bin = "";
	while(num!=0){
		if(num%2)
			bin = "1" + bin;
		else
			bin = "0" + bin;
		num/=2;		
	}
	while(bin.size()<8)
		bin = "0" + bin;
	return bin;
}

string str_to_binary(string s){
	string res = "";
	for(int i=0;i<s.size();i++){
		int num = (int)s[i];
		string bin = dec_to_binary(num);
		res += bin;	
	}
	return res;
}

string pad_string(string input){
	input = str_to_binary(input);	
	string inp = dec_to_binary(input.size());
	input += "1";
	while(input.size()<448)
		input += "0";
	while(inp.size()<64)
		inp = "0" + inp;
	input += inp;
	return input;
}

string hex_to_binary(string hex){
	map<char, string> hexcodes;
	hexcodes['1'] = "0001"; hexcodes['2'] = "0010"; hexcodes['3'] = "0011"; hexcodes['4'] = "0100";
	hexcodes['5'] = "0101"; hexcodes['6'] = "0110"; hexcodes['7'] = "0111"; hexcodes['8'] = "1000";
	hexcodes['9'] = "1001"; hexcodes['A'] = "1010"; hexcodes['B'] = "1011"; hexcodes['C'] = "1100";
	hexcodes['D'] = "1101"; hexcodes['E'] = "1110"; hexcodes['F'] = "1111"; hexcodes['0'] = "0000";
	string res = "";	
	for(int i=0;i<hex.size();i++){
		res += hexcodes[(hex[i])];
	}
	return res;
}

string binary_to_hex(string bin){
	map<string,string> hexcodes;
	hexcodes["0001"] = "1"; hexcodes["0010"] = "2"; hexcodes["0011"] = "3"; hexcodes["0100"] = "4";
	hexcodes["0101"] = "5"; hexcodes["0110"] = "6"; hexcodes["0111"] = "7"; hexcodes["1000"] = "8";
	hexcodes["1001"] = "9"; hexcodes["1010"] = "A"; hexcodes["1011"] = "B"; hexcodes["1100"] = "C";
	hexcodes["1101"] = "D"; hexcodes["1110"] = "E"; hexcodes["1111"] = "F"; hexcodes["0000"] = "0";
	string res = "";
	for(int i=0;i<=bin.size()-4;i+=4){
		string temp = bin.substr(i,4);
		res += hexcodes[temp];
	}
	return res;
}


string process1(string b, string c, string d){
	string res = "";
	for(int i=0; i<b.size(); i++){
		res += (((b[i]-'0') & (c[i]-'0') | ((1-(b[i]-'0'))&(d[i]-'0')))+'0'); 	
	}
	return res;
}

string process2(string b, string c, string d){
	string res = "";
	for(int i=0; i<b.size(); i++){
		res += (((b[i]-'0')^(c[i]-'0')^(d[i]-'0')) +'0'); 	
	}
	return res;
}

string process3(string b, string c, string d){
	string res = "";
	for(int i=0; i<b.size(); i++){
		res += ((((b[i]-'0')&(c[i]-'0'))|((b[i]-'0')&(d[i]-'0'))|((c[i]-'0')&(d[i]-'0'))) +'0'); 	
	}
	return res;
}

string process4(string b, string c, string d){
	string res = "";
	for(int i=0; i<b.size(); i++){
		res += (((b[i]-'0')^(c[i]-'0')^(d[i]-'0')) +'0'); 	
	}
	return res;
}

string addition(string a, string b){
	string res = "";
	for(int i=0;i<a.size();i++){
		res += (((a[i]-'0')^(b[i]-'0'))+'0');
	}
	return res;
}

string round_SHA(string a,string b, string c, string d, string e, string w, string k, int process){
	string res = "";
	string p_res;
	switch(process){
		case 1: p_res = process1(b,c,d); break;
		case 2: p_res = process2(b,c,d); break;
		case 3: p_res = process3(b,c,d); break;
		case 4: p_res = process4(b,c,d);
	}
	
}
string shift(string s,int k)
{
	string ans="";
	string t=s.substr(0,k);
	string m=s.substr(k,32-k);
	ans+=m;
	ans+=t;
	return ans;
	
}

	
void round1(string &a,string &b,string &c,string &d,string &e,string w,string k)
{
	string f=process1(b,c,d);
	string temp1=addition(f,e);
	string a_shift=shift(a,5);
	//cout<<a<<endl;
	//cout<<a_shift<<endl;
	string temp2=addition(temp1,a_shift);
	cout<<temp2<<endl;
	string temp_f=addition(addition(temp2,w),k);
	string b_shift=shift(b,30);
	e=d;
	d=c;
	c=b_shift;
	b=a;
	a=temp_f;
}
void round2(string &a,string &b,string &c,string &d,string &e,string w,string k)
{
	string f=process2(b,c,d);
	string temp1=addition(f,e);
	string a_shift=shift(a,5);
	//cout<<a<<endl;
	//cout<<a_shift<<endl;
	string temp2=addition(temp1,a_shift);
	cout<<temp2<<endl;
	string temp_f=addition(addition(temp2,w),k);
	string b_shift=shift(b,30);
	e=d;
	d=c;
	c=b_shift;
	b=a;
	a=temp_f;
}
int main(){
	string input;
	getline(cin, input);
	cout << binary_to_hex(pad_string(input)) << endl;
	string a = hex_to_binary("01234567");
	string b = hex_to_binary("89ABCDEF");
	string c = hex_to_binary("FEDCBA98");
	string d = hex_to_binary("76543210");
	string e = hex_to_binary("C3D2E1F0");
	//cout << "\nProcess 1\n";	
	cout << binary_to_hex(process1(b,c,d)) << endl;
	//cout << "\nProcess 2\n";	
	cout << binary_to_hex(process2(b,c,d)) << endl;
	//cout << "\nProcess 3\n";	
	cout << binary_to_hex(process3(b,c,d)) << endl;
	//cout << "\nProcess 4\n";	
	cout << binary_to_hex(process4(b,c,d)) << endl;
	round1(a,b,c,d,e,hex_to_binary("68656C6C"),hex_to_binary("FEDCBA98"));	
	cout<<binary_to_hex(a)<<" "<<binary_to_hex(b)<<" "<<binary_to_hex(c)<<" "<<binary_to_hex(d)<<" "<<binary_to_hex(e)<<endl;
	cout<<"after round2"<<endl;
	round2(a,b,c,d,e,hex_to_binary("68656C6C"),hex_to_binary("FEDCBA98"));
	cout<<binary_to_hex(a)<<" "<<binary_to_hex(b)<<" "<<binary_to_hex(c)<<" "<<binary_to_hex(d)<<" "<<binary_to_hex(e)<<endl;
	return 0;
}