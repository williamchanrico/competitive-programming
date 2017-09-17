#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int L, N, cut[60], memo[60][60];

int dp(int left, int right){
	if(left + 1 == right)
		return 0;
	if(memo[left][right] != -1)
		return memo[left][right];

	int ans = INF;

	for(int a = left + 1; a < right; a++)
		ans = min(ans, (cut[right] - cut[left]) + dp(left, a) + dp(a, right));

	return memo[left][right] = ans;
}

int main(){
	while(scanf("%d", &L), L){
		scanf("%d", &N);

		cut[0] = 0;
		cut[N + 1] = L;

		for(int a = 1; a <= N; a++)
			scanf("%d", &cut[a]);

		memset(memo, -1, sizeof(memo));

		printf("The minimum cutting is %d.\n", dp(0, N + 1));
	}	
}