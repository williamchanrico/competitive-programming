#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int N, memo[200][200];

int dp(){
	int ans = memo[1][1];

	for(int a = 1; a <= N; a++)
		for(int b = 1; b <= N; b++)
			for(int c = a + 1; c <= (a + N - 1); c++)
				for(int d = b + 1; d <= (b + N - 1); d++)
					ans = max(ans,
						memo[c][d]
						- memo[a - 1][d]
						- memo[c][b - 1]
						+ memo[a - 1][b - 1]);

	return ans;
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		memset(memo, 0, sizeof(memo));

		scanf("%d", &N);

		for(int a = 1; a <= N; a++){
			for(int b = 1; b <= N; b++){
				scanf("%d", &memo[a][b]);
				memo[a + N][b] = memo[a][b + N] = memo[a + N][b + N] = memo[a][b];
			}
		}

		for(int a = 1; a <= (2 * N); a++)
			for(int b = 1; b <= (2 * N); b++)
				memo[a][b] += memo[a - 1][b] + memo[a][b - 1] - memo[a - 1][b - 1];

		printf("%d\n", dp());
	}

}