#include <string>
#include <iostream>
using namespace std;

int main(){
	string inp;
	bool freda, rainbow;
	int n;
	
	cin >> n;
	getline(cin, inp);
	while(n>0){
		getline(cin, inp);
		if(inp.find("miao.")==0)
			rainbow=true;
		else
			rainbow=false;
		if(inp.rfind("lala.")==inp.size()-5)
			freda=true;
		else
			freda=false;
		if(rainbow && !freda)
			cout << "Rainbow's\n";
		else if(!rainbow && freda)
			cout << "Freda's\n";
		else
			cout << "OMG>.< I don't know!\n";
		n--;
	}
	
	
}