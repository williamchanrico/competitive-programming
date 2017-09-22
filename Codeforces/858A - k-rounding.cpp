#include <bits/stdc++.h>
using namespace std;

long long gcd(int x, int y){ return (y == 0 ? x : gcd(y, x % y)); }

long long lcm(int x, int y){ return (x / gcd(x, y) * y); }

long long pow(int x, int y){
	long long ans = 1;

	while(y--){
		ans *= x;
	}

	return ans;
}

int main(){
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%lld\n", lcm(N, pow(10, K)));
}