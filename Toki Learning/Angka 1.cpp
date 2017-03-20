#include <bits/stdc++.h>
using namespace std;

int N, Q=2;

int main(){
	cin >> N;
	for(int a=1, b=0, c=2;b<N;b++, c++){
		cout << a << "\n"; a+=c;
	}
}
