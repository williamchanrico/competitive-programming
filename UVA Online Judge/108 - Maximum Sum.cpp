#include <bits/stdc++.h>

#define INF 1000111222

int memo[105][105];

int calculate(int N){
	int maxSum = -INF;

	for(int a = 1; a <= N; a++)
		for(int b = 1; b <= N; b++)
			for(int c = a + 1; c <= N; c++)
				for(int d = b + 1; d <= N; d++){
					maxSum = std::max(maxSum, 
						memo[c][d] 
						- memo[a - 1][d] 
						- memo[c][b - 1] 
						+ memo[a - 1][b - 1]);
				}
	return maxSum;
}

int main(){
	// freopen("in.txt", "r", stdin);
	int inputN;

	scanf("%d", &inputN);

	memset(memo, 0, sizeof(memo));

	for(int a = 1; a <= inputN; a++){
		for(int b = 1; b <= inputN; b++){
			scanf("%d", &memo[a][b]);
			memo[a][b] += memo[a - 1][b] + memo[a][b - 1] - memo[a - 1][b - 1];
		}
	}

	printf("%d\n", calculate(inputN));
}