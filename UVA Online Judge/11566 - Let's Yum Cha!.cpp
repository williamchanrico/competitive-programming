#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int N, X, T, K, money, price[110], value[110], memo[110][1100][210];

int dp(int n, int total, int count){
	int bill = ceil(1.1L  * (double) (total + (N * T)));

	if(count > (2 * N) || bill > money)
		return -INF;
	if(n == K || count == (2 * N) || bill == money)
		return 0;
	if(memo[n][total][count] != -1)
		return memo[n][total][count];
	
	return memo[n][total][count] = max(dp(n + 1, total, count),
		max(value[n] + dp(n + 1, total + price[n], count + 1), 
			(value[n] * 2) + dp(n + 1, total + (price[n] * 2), count + 2)));
}

int main(){
	while(scanf("%d %d %d %d", &N, &X, &T, &K), (N | X | T | K)){
		N++;

		money = X * N;

		for(int a = 0; a < K; a++){
			int inp;

			scanf("%d", &price[a]);

			value[a] = 0;
			for(int b = 0; b < N; b++){
				scanf("%d", &inp);

				value[a] += inp;
			}
		}

		memset(memo, -1, sizeof(memo));

		printf("%.2lf\n", (double) dp(0, 0, 0) / N);
	}
}
