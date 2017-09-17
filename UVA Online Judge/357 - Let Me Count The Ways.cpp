#include <bits/stdc++.h>
using namespace std;

int coinType = 5;
int coinValue[] = {1, 5, 10, 25, 50};
long long memo[6][30001];

long long ways(int type, int value){
	if(value == 0) 
		return 1;
	if(value < 0 || type == coinType)
		return 0;
	if(memo[type][value] != -1)
		return memo[type][value];
	return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main(){
	int inp;

	memset(memo, -1, sizeof(memo));

	while(scanf("%d", &inp) != EOF){
		long long ans = ways(0, inp);

		if(ans == 1)
			printf("There is only 1 way to produce %d cents change.\n", inp);
		else
			printf("There are %lld ways to produce %d cents change.\n", ans, inp);
	}
}