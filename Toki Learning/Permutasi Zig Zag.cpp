#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;

bool allowed(string x){
	int n=0;
	while(n+2<x.size()){
		if(!((x[n+1]<x[n] && x[n+1]<x[n+2]) || (x[n+1]>x[n] && x[n+1]>x[n+2])))
			return false;
		n++;
	}
	return true;
}

int main(){
	int inp;
	string str;
	cin >> inp;
	for(char a='1';a<(char)(inp+49);a++) str+=a;
	do{
		if(allowed(str)) cout << v[a] << "\n";
	}while(next_permutation(str.begin(), str.end()));
}