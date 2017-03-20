#include <bits/stdc++.h>
using namespace std;

string inp;

int main(){
	while(getline(cin, inp)){
		for(int a=0, sz=inp.size();a<sz;a++)
			cout << (char)(inp[a]-7);
		cout << "\n";
	}
}