#include <bits/stdc++.h>
using namespace std;

long long memo[75][75][2];

long long dp(int idx, int locks, int lockedAbove)
{
    if (idx == 0 && locks == 0)
        return 1;
    if (idx < 0 || locks < 0)
        return 0;
    if (memo[idx][locks][lockedAbove] != -1)
        return memo[idx][locks][lockedAbove];

    return memo[idx][locks][lockedAbove] = dp(idx - 1, locks, 0)
        + dp(idx - 1, locks - (lockedAbove ? 1 : 0), 1);
}

int main()
{
    int N, S;

    memset(memo, -1, sizeof(memo));

    while (scanf("%d %d", &N, &S), (N + S >= 0)) {
        printf("%lld\n", dp(N, S, 1));
    }
}

/* Reversed top-down (slower)

#include <bits/stdc++.h>
using namespace std;

int N, S;
long long memo[75][75][2];

long long dp(int idx, int locks, int lockedAbove){
	if(idx == N)
		return (locks == S);
	if(memo[idx][locks][lockedAbove] != -1)
		return memo[idx][locks][lockedAbove];

	return memo[idx][locks][lockedAbove] = dp(idx + 1, locks, 0) 
		+ dp(idx + 1, locks + (lockedAbove ? 1 : 0), 1);
}

int main(){
	while(scanf("%d %d", &N, &S), (N + S >= 0)){
		memset(memo, -1, sizeof(memo));

		printf("%lld\n", dp(0, 0, 1));
	}
}

*/