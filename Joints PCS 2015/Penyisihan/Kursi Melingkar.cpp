// Fors

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long memo[1010];

long long f(long long x){
	if(memo[x]!=-1)
		return memo[x];
	return memo[x] = (f(x-1) + f(x-2)-2) % MOD;
}

int main(){
	long long N;

	memset(memo, -1, sizeof(memo));

	memo[0]=0;
	memo[1]=1;
	memo[2]=2;
	memo[3]=6;
	memo[4]=9;

	cin >> N;
	
	cout << f(N) << "\n";
}