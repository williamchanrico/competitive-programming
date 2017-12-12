#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int N[30], M;
double P[30], memo[30][1100];

void fflush(){
	char c;

	while( (c = getchar()) != EOF && c != '\n');
}

void resetMemo(){
	for(int a = 0; a < 30; a++)
		for(int b = 0; b < 1100; b++)
			memo[a][b] = -1.0;
}

double dp(int idx, int count){
	if(count <= 0 || idx < 0)
		return (idx < 0 ? INF : 0);
	if(memo[idx][count] != -1.0)
		return memo[idx][count];

	return memo[idx][count] = min(dp(idx - 1, count), P[idx] + dp(idx, count - N[idx]));
}

int main(){
	int TC = 0;

	N[0] = 1;

	while(scanf("%lf %d", &P[0], &M) != EOF){

		resetMemo();

		for(int a = 1; a <= M; a++)
			scanf("%d %lf", &N[a], &P[a]);
		
		fflush();

		string inp;

		getline(cin, inp);

		stringstream ss(inp);

		int K;

		printf("Case %d:\n", ++TC);

		while(ss >> K){
			printf("Buy %d for $%.2lf\n", K, dp(M, K));
		}
	}
}
