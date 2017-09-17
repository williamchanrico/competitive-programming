#include <bits/stdc++.h>
using namespace std;

int N, M, K, S, P, memo[110][110];

void dp(){
	S = P = 0;

	for(int a = 1; a <= N; a++){
		for(int b = 1; b <= M; b++){
			for(int c = a; c <= N; c++){
				for(int d = b; d <= M; d++){
					int n = c - a + 1;
					int m = d - b + 1;
					int cost = memo[c][d] - memo[a - 1][d] - memo[c][b - 1] + memo[a - 1][b - 1];

					if(n * m >= S && cost <= K){
						if(n * m == S)
							P = min(cost, P);
						else
							P = cost;
						S = n * m;
					}
				}
			}
		}
	}
}

int main(){
	int T;

	scanf("%d", &T);

	for(int TC = 1; TC <= T; TC++){
		scanf("%d %d %d", &N, &M, &K);

		memset(memo, 0, sizeof(memo));

		for(int a = 1; a <= N; a++){
			for(int b = 1; b <= M; b++){
				scanf("%d", &memo[a][b]);

				memo[a][b] += memo[a - 1][b] + memo[a][b - 1] - memo[a - 1][b - 1];
			}
		}

		dp();

		printf("Case #%d: %d %d\n", TC, S, P);
	}
}
