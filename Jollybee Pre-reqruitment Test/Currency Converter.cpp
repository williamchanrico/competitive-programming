#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string, int> m;
	int N;
	int theNum;
	int ans = 0;
	string cur;

	cin >> N;
	cin.ignore();

	for(int a = 0; a < N; a++){
		cin >> cur >> theNum;
		m[cur] = theNum;
	}

	for(int a = 0; a < N; a++){
		cin >> cur >> theNum;
		ans += m[cur] * theNum;
	}
	
	cout << ans << "\n";
}