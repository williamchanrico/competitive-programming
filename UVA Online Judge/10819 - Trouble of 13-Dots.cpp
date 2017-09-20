#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int M, N, P[110], F[110], memo[110][11000];

int dp(int item, int total){
	if(total > (M + 200) || (total > M && M < 1800))
		return -INF;
	if(item == N)
		return ((total > M && total <= 2000) ? -INF : 0);
	if(memo[item][total] != -1)
		return memo[item][total];

	return memo[item][total] = max(dp(item + 1, total), F[item] + dp(item + 1, total + P[item]));
}

int main(){
	while(scanf("%d %d", &M, &N) != EOF){
		for(int a = 0; a < N; a++)
			scanf("%d %d", &P[a], &F[a]);

		memset(memo, -1, sizeof(memo));

		printf("%d\n", dp(0, 0));
	}
}
