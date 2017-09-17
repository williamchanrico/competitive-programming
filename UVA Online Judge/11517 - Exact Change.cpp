#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int price;
int coinType;
int coinValue[101];
int memo[101][20000];

int dp(int type, int value){
	if(value == 0)
		return 0;
	if(value < 0 || type == coinType)
		return INF;
	if(memo[type][value] != -1)
		return memo[type][value];
	
	return memo[type][value] = min(dp(type + 1, value), 1 + dp(type + 1, value - coinValue[type]));
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &price, &coinType);

		for(int a = 0; a < coinType; a++)
			scanf("%d", &coinValue[a]);

		memset(memo, -1, sizeof(memo));

		for(int a = price; a <= 20000; a++){
			if(dp(0, a) != INF){
				printf("%d %d\n", a, memo[0][a]);

				break;
			}
		}
	}
}