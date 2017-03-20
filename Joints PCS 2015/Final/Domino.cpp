#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long memo[10000];

long long hitung(int x){
	if(memo[x]!=-1)
		return memo[x];

	if(x==0 || x==1)
		return 1;

	memo[x] = (4 * hitung(x - 1) - hitung(x - 2)) % MOD;
	
	return memo[x] = (memo[x] < 0 ? memo[x] + MOD : memo[x]);
}

int main(){
	int n;

	memset(memo, -1, sizeof(memo));

	cin >> n;

	cout << hitung(n + 1) << "\n";
}