#include <bits/stdc++.h>
using namespace std;

int N, dp[10][7500], coin[5]={1, 5, 10, 25, 50};

int ways(int id, int val){
	if(val==0) return 1;
	if(val<0 || id==5) return 0;
	if(dp[id][val]!=-1) return dp[id][val];
	return dp[id][val]=ways(id+1, val)+ways(id, val-coin[id]);
}

int main(){
	memset(dp, -1, sizeof(dp));
	while(scanf("%d", &N)!=EOF)
		printf("%d\n", ways(0, N));
}