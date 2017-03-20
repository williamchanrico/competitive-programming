#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string inp;
	getline(cin, inp);
	while(inp!="#"){
		string temp=inp, tempp=inp;
		next_permutation(temp.begin(), temp.end());
		sort(tempp.begin(), tempp.end());
		if(temp==tempp)
			cout << "No Successor\n";
		else
			cout << temp << "\n";
		
		getline(cin, inp);
	}
}