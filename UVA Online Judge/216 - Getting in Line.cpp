#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int N, x[10], y[10], p[10][1 << 10];
double dist[10][10], memo[10][1 << 10];

double hypot(int x, int y){
	return sqrt((double) x * x + (double) y * y);
}

double dp(int pos, int bitmask){
	if(bitmask == ((1 << N) - 1))
		return 0;
	if(memo[pos][bitmask] != -1.0)
		return memo[pos][bitmask];

	memo[pos][bitmask] = INF;

	for(int a = 0; a < N; a++){
		if(pos != a && !(bitmask & (1 << a))){
			double next = dist[pos][a] + dp(a, bitmask | (1 << a));

			if(next < memo[pos][bitmask]){
				memo[pos][bitmask] = next;
				p[pos][bitmask] = a; 
			}
		}
	}

	return memo[pos][bitmask];
}

int main(){
	int TC = 1;

	while(scanf("%d", &N), N){
		for(int a = 0; a < N; a++)
			scanf("%d %d", &x[a], &y[a]);

		for(int a = 0; a < N; a++)
			for(int b = 0; b < N; b++)
				dist[a][b] = dist[b][a] = hypot(x[b] - x[a], y[b] - y[a]) + 16.00;


		for(int a = 0; a < N; a++)
			for(int b = 0; b < (1 << N); b++)
				memo[a][b] = -1.0;

		int startNode;
		double ans = INF;

		for(int start = 0; start < N; start++){
			double tempAns = dp(start, 0 | (1 << start));

			if(tempAns < ans){
				ans = tempAns;	
				startNode = start;
			}
		}

		printf("**********************************************************\n");
		printf("Network #%d\n", TC++);

		int currNode = startNode;
		int currMask = (0 | (1 << startNode));

		for(int a = 0; a < (N - 1); a++){
			int nextNode = p[currNode][currMask];

			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
				x[currNode], y[currNode], x[nextNode], y[nextNode], dist[currNode][nextNode]);

			currNode = nextNode;
			currMask |= (1 << nextNode);
		}

		printf("Number of feet of cable required is %.2lf.\n", ans);
	}
}
