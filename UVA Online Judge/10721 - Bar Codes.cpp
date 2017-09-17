#include <bits/stdc++.h>
using namespace std;

int N, K, M;
long long memo[60][60];

long long dp(int units, int bars){
	if(bars == K)
		return (units == N);
	if(memo[units][bars] != -1)
		return memo[units][bars];

	memo[units][bars] = 0;

	for(int a = 1; a <= M; a++)
		if(units + a <= N)
			memo[units][bars] += dp(units + a, bars + 1);
		else
			break;

	return memo[units][bars];
}

int main(){
	while(scanf("%d %d %d", &N, &K, &M) != EOF){
		memset(memo, -1, sizeof(memo));

		printf("%lld\n", dp(0, 0));
	}
}