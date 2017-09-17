#include <bits/stdc++.h>
using namespace std;

int N, M, Q, D, memo[210][210][15];
vector<int> v(210);

int dp(int n, int sum, int ways){
	if(ways == M && sum == 0)
		return 1;
	if(n == N || (ways == M && sum != 0))
		return 0;
	if(memo[n][sum][ways] != -1)
		return memo[n][sum][ways];
	return memo[n][sum][ways] = dp(n + 1, sum % D, ways) + dp(n + 1, (sum + v[n]) % D, ways + 1);
}

int main(){
	int TC = 1;

	while(scanf("%d %d", &N, &Q) && (N | Q)){
		for(int a = 0; a < N; a++)
			scanf("%d", &v[a]);


		printf("SET %d:\n", TC++);

		for(int a = 1; a <= Q; a++){
			scanf("%d %d", &D, &M);
			
			memset(memo, -1, sizeof(memo));

			int ans = dp(0, 0, 0);
			printf("QUERY %d: %d\n", a, ans);
		}
	}
}