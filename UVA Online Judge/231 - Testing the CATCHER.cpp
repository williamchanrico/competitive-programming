#include <bits/stdc++.h>

#define INF 1000111222

int memo[10000];
std::vector<int> v;

int lis(int n){
	if(n == 0) return 1;
	if(memo[n] != -1) return memo[n];

	int maxValue = 1;

	for(int a = 0; a < n; a++)
		if(v[a] >= v[n]){
			maxValue = std::max(maxValue, lis(a) + 1);
		}
	return memo[n] = maxValue;
}

int main(){
	// freopen("in.txt", "r", stdin);
	int T = 1;

	while(true){
		int input;

		scanf("%d", &input);

		if(input != -1)
			v.push_back(input);

		if(input == -1 && v.size() == 0) return 0;


		if(input == -1){
			memset(memo, -1, sizeof(memo));

			int ans = -INF;

			for(int a = 0; a < v.size(); a++)
				ans = std::max(ans, lis(a));

			printf("%sTest #%d:\n", (T != 2 ? "\n" : ""), T++);
			printf("  maximum possible interceptions: %d\n", ans);
			v.clear();
		}
	}
}