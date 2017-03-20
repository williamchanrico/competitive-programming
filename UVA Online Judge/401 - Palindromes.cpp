#include <iostream>
#include <map>
using namespace std;

string inp;

map<char, char> m;

void prepare(){
	for(char a='1';a<='9';a++)
		m[a]='.';
	for(char a='A';a<='Z';a++)
		m[a]='.';
	m['A']='A';
	m['E']='3';
	m['H']='H';
	m['I']='I';
	m['J']='L';
	m['L']='J';
	m['M']='M';
	m['O']='O';
	m['S']='2';
	m['T']='T';
	m['U']='U';
	m['V']='V';
	m['W']='W';
	m['X']='X';
	m['Y']='Y';
	m['Z']='5';
	m['1']='1';
	m['2']='S';
	m['3']='E';
	m['5']='Z';
	m['8']='8';
}

bool palindrome(string x){
	for(int a=0, b=x.size()-1;a<b;a++, b--)
		if(x[a]!=x[b]) return false;
	return true;
}

bool reverse(string x){
	for(int a=0, b=x.size()-1;a<=b;a++, b--)
		if(m[x[a]]!=x[b]) return false;
	return true;
}

int main(){
	prepare();
	while(cin >> inp){
		bool pal,rev;
		pal=palindrome(inp);
		rev=reverse(inp);
		if(pal && rev)
			cout << inp << " -- is a mirrored palindrome.\n\n";
		else if(pal)
			cout << inp << " -- is a regular palindrome.\n\n";
		else if(rev)
			cout << inp << " -- is a mirrored string.\n\n";
		else
			cout << inp << " -- is not a palindrome.\n\n";
	}
}