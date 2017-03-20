#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 1000000000

int m, n;
int p[105], f[105], dp[105][10205];

int solve(int in, int total){
	if((total>m && m<1800) || (total>(m+200))) return -INF;
	if(in==n){
		if(total>m && total<=2000) return -INF;
		return 0;
	}
	if(dp[in][total]==-1)
		dp[in][total]=max(solve(in+1, total), solve(in+1, total+p[in])+f[in]);
	return dp[in][total];
}

int main(){
	while(scanf("%d %d", &m, &n) != EOF){
		memset(dp, -1, sizeof(dp));
		for(int a=0;a<n;a++)
			scanf("%d %d", &p[a], &f[a]);
		printf("%d\n", solve(0, 0));
	}
}