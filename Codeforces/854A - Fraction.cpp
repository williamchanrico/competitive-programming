#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){ return (y == 0 ? x : gcd(y, x % y)); }

int main(){
	int N;

	scanf("%d", &N);

	for(int a = N / 2; a > 0; a--){
		int denom = N - a;

		if(gcd(a, denom) == 1){
			printf("%d %d\n", a, denom);

			break;
		}
	}
}
