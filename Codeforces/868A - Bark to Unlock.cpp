#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string inp[110], pass, ans = "";

	cin >> pass >> N;

	for(int a = 0; a < N; a++){
		cin >> inp[a];

		for(int b = 0; b <= a; b++){
			ans += inp[a] + inp[b];
			ans += inp[b] + inp[a];
		}
	}

	if(ans.find(pass) != string::npos)
		cout << "YES\n";
	else
		cout << "NO\n";
}


/*

#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string inp[110], pass;
	map<string, bool> m;

	cin >> pass >> N;

	for(int a = 0; a < N; a++){
		cin >> inp[a];

		m[inp[a]] = true;

		for(int b = 0; b <= a; b++){
			m[string(1, inp[a][1]) + string(1, inp[b][0])] = true;
			m[string(1, inp[b][1]) + string(1, inp[a][0])] = true;
		}
	}

	if(m.count(pass))
		cout << "YES\n";
	else
		cout << "NO\n";
}

*/