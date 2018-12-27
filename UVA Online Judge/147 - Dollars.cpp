#include <bits/stdc++.h>
using namespace std;

long long memo[31000];

int main()
{
    int dollar, cent, coinValue[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

    while (scanf("%d.%d", &dollar, &cent), (dollar | cent)) {
        int target = (dollar * 100) + cent;

        memset(memo, 0, sizeof(memo));

        memo[0] = 1;

        for (int a = 0; a < sizeof(coinValue) / sizeof(coinValue[0]); a++)
            for (int b = coinValue[a]; b <= target; b++)
                memo[b] += memo[b - coinValue[a]];

        printf("%3d.%02d%17lld\n", dollar, cent, memo[target]);
    }
}

/* Top Down

#include <bits/stdc++.h>
using namespace std;

long long memo[15][31000];
int dollar, cent, target, coinValue[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long dp(int idx, int sum){
	if(sum == target)
		return 1;
	if(sum > target || idx == sizeof(coinValue) / sizeof(coinValue[0]))
		return 0;
	if(memo[idx][sum] != -1)
		return memo[idx][sum];

	return memo[idx][sum] = dp(idx, sum + coinValue[idx]) + dp(idx + 1, sum);
}

int main(){
	while(scanf("%d.%d", &dollar, &cent), (dollar | cent)){
		target = (dollar * 100) + cent;

		memset(memo, -1, sizeof(memo));

		printf("%3d.%02d%17lld\n", dollar, cent, dp(0, 0));
	}
}

*/