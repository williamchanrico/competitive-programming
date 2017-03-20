#include <iostream>
#include <ctype.h>
using namespace std;

string inp;

string xxx(string x){
	string ans;
	for(int a=0, b=0, sz=x.size();a<sz;a++)
		if(x[a]!=',' && x[a]!=' ' && x[a]!='.' && x[a]!='?' && x[a]!='!'){
			ans += (char)tolower(x[a]);
			b++;
		}
	return ans;
}

bool palindrome(string x){
	for(int a=0, b=x.size()-1;a<b;a++, b--)
		if(x[a]!=x[b]) return false;
	return true;
}

int main(){
	getline(cin, inp);
	while(inp!="DONE"){
		inp=xxx(inp);
		if(palindrome(inp)) cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
		getline(cin, inp);
	}
}