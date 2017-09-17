#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int memo[100 + 10][100 + 10];

int dp(int N){
	int maxSum = -INF;

	for(int a = 1; a <= N; a++)
		for(int b = 1; b <= N; b++)
			for(int c = a + 1; c <= N; c++)
				for(int d = b + 1; d <= N; d++)
					maxSum = max(maxSum, 
						memo[c][d] - memo[a - 1][d] - memo[c][b - 1] + memo[a - 1][b - 1]);

	return maxSum;
}

int main(){
	int N;

	memset(memo, 0, sizeof(memo));

	scanf("%d", &N);

	for(int a = 1; a <= N; a++){
		for(int b = 1; b <= N; b++){
			scanf("%d", &memo[a][b]);
			memo[a][b] += memo[a - 1][b] + memo[a][b - 1] - memo[a - 1][b - 1];
		}
	}

	printf("%d\n", dp(N));
}