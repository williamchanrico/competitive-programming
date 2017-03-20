#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int L, n, A[60], memo[60][60];

int cut(int left, int right){
	if(left+1==right) return 0;
	if(memo[left][right]!=-1) return memo[left][right];
	int ans=INF;
	for(int a=left+1;a<right;a++)
		ans=min(ans, cut(left, a)+cut(a, right)+(A[right]-A[left]));
	return memo[left][right]=ans;
}

int main(){
	while(scanf("%d", &L), L){
		scanf("%d", &n);
		A[0]=0;
		for(int a=1;a<=n;a++)
			scanf("%d", &A[a]);
		A[n+1]=L;
		memset(memo, -1, sizeof(memo));
		printf("The minimum cutting is %d.\n", cut(0, n+1));
	}
}