#include <bits/stdc++.h>
using namespace std;

int T, N, MW, G, V[1010], W[1010], dp[1010][40];

int val(int id, int remW){
	if(id==N || remW==0) return 0;
	if(dp[id][remW]!=-1) return dp[id][remW];
	if(W[id]>remW) return dp[id][remW]=val(id+1, remW);
	return dp[id][remW]=max(val(id+1, remW), V[id]+val(id+1, remW-W[id]));
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for(int a=0;a<N;a++)
			scanf("%d %d", &V[a], &W[a]);
		int ans=0;
		scanf("%d", &G);
		while(G--){
			scanf("%d", &MW);
			ans+=val(0, MW);
		}
		printf("%d\n", ans);
	}
}