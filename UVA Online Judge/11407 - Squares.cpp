#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int memo[11000];

int dp(int sum){
	if(sum <= 0)
		return (sum < 0 ? INF : 0);
	if(memo[sum] != -1)
		return memo[sum];

	memo[sum] = INF;

	for(int a = 1; a <= 1000; a++)
		if(a * a <= sum)
			memo[sum] = min(memo[sum], 1 + dp(sum - (a * a)));
		else
			break;
		
	return memo[sum];
}

int main(){
	int T;

	memset(memo, -1, sizeof(memo));

	scanf("%d", &T);

	while(T--){
		int N;

		scanf("%d", &N);
		
		printf("%d\n", dp(N));
	}
}