#include <bits/stdc++.h>

#define INF 1000111222

int inputM;
int inputC;
int inputPrice[25][25];
int memo[205][25];

int shop(int moneyLeft, int garmentNumber){
	if(moneyLeft < 0) return -INF;
	if(garmentNumber == inputC) return inputM - moneyLeft;
	if(memo[moneyLeft][garmentNumber] != -1) return memo[moneyLeft][garmentNumber];

	int ret = -INF;

	for(int a = 1; a <= inputPrice[garmentNumber][0]; a++)
		ret = std::max(ret, shop(moneyLeft - inputPrice[garmentNumber][a], garmentNumber + 1));

	return memo[moneyLeft][garmentNumber] = ret;
}

int main(){
	// freopen("in.txt", "r", stdin);
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &inputM, &inputC);

		for(int a = 0; a < inputC; a++){
			scanf("%d", &inputPrice[a][0]);
			for(int b = 1; b <= inputPrice[a][0]; b++)
				scanf("%d", &inputPrice[a][b]);
		}

		memset(memo, -1, sizeof(memo));

		int ans = shop(inputM, 0);

		if(ans < 0) printf("no solution\n");
		else printf("%d\n", ans);
	}
}