#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000

int T, n, xSize, ySize, x[50], y[50], dist[25][25], memo[25][1<<11];

int tsp(int pos, int bitmask){
	if(bitmask==(1<<(n+1))-1) return dist[pos][0];
	if(memo[pos][bitmask]!=-1) return memo[pos][bitmask];
	int ans=INF;
	for(int next=0;next<=n;next++)
		if(pos!=next && !(bitmask&(1<<next)))
			ans=min(ans, dist[pos][next]+tsp(next, bitmask|(1<<next)));
	return memo[pos][bitmask]=ans;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &xSize, &ySize);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for(int a=1;a<=n;a++)
			scanf("%d %d", &x[a], &y[a]);
		for(int a=0;a<=n;a++)
			for(int b=0;b<=n;b++)
				dist[a][b]=abs(x[a]-x[b])+abs(y[a]-y[b]);
		memset(memo, -1, sizeof(memo));
		printf("The shortest path has length %d\n", tsp(0, 1));
	}
}