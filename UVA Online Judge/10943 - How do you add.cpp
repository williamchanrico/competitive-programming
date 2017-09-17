#include <bits/stdc++.h>
using namespace std;

int N, K, memo[110][110];

int dp(int sum, int count){
	if(sum > N || count > K)
		return 0;
	if(count == K)
		return (sum == N);
	if(memo[sum][count] != -1)
		return memo[sum][count];

	memo[sum][count] = 0;

	for(int a = 0; a <= N; a++)
		memo[sum][count] = (memo[sum][count] + dp(sum + a, count + 1)) % 1000000;

	return memo[sum][count];
}

int main(){
	while(scanf("%d %d", &N, &K), (N | K)){
		memset(memo, -1, sizeof(memo));

		printf("%d\n", dp(0, 0));
	}
}