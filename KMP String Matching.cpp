#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1100000

string str, strP;
int backTable[MAX_N];

void kmpPreprocess(){
	int a = 0, b = -1;

	backTable[0] = -1;

	while(a < strP.size()){
		while(b >= 0 && strP[a] != strP[b])
			b = backTable[b];

		a++;
		b++;

		backTable[a] = b;
	}
}

void kmpSearch(){
	int a = 0, b = 0;

	while(a < str.size()){
		while(b >= 0 && str[a] != strP[b])
			b = backTable[b];

		a++;
		b++;

		if(b == strP.size()){
			cout << "Pattern found at " << a - b << "\n";

			b = backTable[b];
		}
	}
}

int main(){
	cin >> str >> strP;

	kmpPreprocess();

	kmpSearch();
}