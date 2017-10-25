#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int M, C, price[30][30], memo[210][30];

int dp(int money, int idx){
	if(money > M) return -INF;
	if(idx == C) return money;
	if(memo[money][idx] != -1) return memo[money][idx];

	int ans = -INF;

	for(int a = 1; a <= price[idx][0]; a++)
		ans = max(ans, dp(money + price[idx][a], idx + 1));

	return memo[money][idx] = ans;
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &M, &C);

		for(int a = 0; a < C; a++){
			scanf("%d", &price[a][0]);

			for(int b = 0; b < price[a][0]; b++)
				scanf("%d", &price[a][b + 1]);
		}

		memset(memo, -1, sizeof(memo));

		int ans = dp(0, 0);

		if(ans == -INF)
			printf("no solution\n");
		else
			printf("%d\n", ans);
	}

}