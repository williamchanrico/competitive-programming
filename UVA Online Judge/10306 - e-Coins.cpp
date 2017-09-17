#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int target;
int coinType;
int aValue[40 + 10];
int bValue[40 + 10];
int memo[300 + 10][300 + 10][300 + 10];

double calcValue(int value, int aValueSum, int bValueSum){
	return (double) value - sqrt((aValueSum * aValueSum) + (bValueSum * bValueSum));
}

int dp(int value, int aValueSum, int bValueSum){
	double remValue = calcValue(value, aValueSum, bValueSum);

	if(abs(remValue - 0) < 1e-9)
		return 0;
	if(remValue < 0)
		return INF;
	if(memo[value][aValueSum][bValueSum] != -1)
		return memo[value][aValueSum][bValueSum];

	int ans = INF;

	for(int type = 0; type < coinType; type++){
		int aTotal = (aValueSum + aValue[type]);
		int bTotal = (bValueSum + bValue[type]);

		ans = min(ans, 1 + dp(value, aTotal, bTotal));
	}

	return memo[value][aValueSum][bValueSum] = ans;
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &coinType, &target);

		for(int a = 0; a < coinType; a++){
			scanf("%d %d", &aValue[a], &bValue[a]);
		}

		memset(memo, -1, sizeof(memo));

		int ans = dp(target, 0, 0);

		if(ans != INF)
			printf("%d\n", ans);
		else
			printf("not possible\n");
	}
}