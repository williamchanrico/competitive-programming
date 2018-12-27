#include <bits/stdc++.h>
using namespace std;

#define MOD 98765431

long long N, T, C[51000];

long long modPow(long long x, long long y, long long m)
{
    long long ans = 1;

    while (y > 0) {
        if (y % 2)
            ans = (ans * x) % m;

        y >>= 1;

        x = (x * x) % m;
    }

    return ans;
}

long long inverse(long long x, long long m)
{
    return modPow(x, m - 2, m);
}

// f(N, T) = (N^T + ((-1)^T * N)) / (N + 1)
// T ganjil	-> 	next = f(N, T) + 1
// T genap	-> 	next = f(N, T) - 1

int main()
{
    scanf("%lld %lld", &N, &T);

    for (int a = 0; a < N; a++)
        scanf("%lld", &C[a]);

    long long temp1 = ((modPow(N - 1, T, MOD) + (T % 2 ? -(N - 1) : (N - 1))) * inverse(N, MOD)) % MOD;
    long long temp2 = (T % 2 ? (temp1 + 1 + MOD) : (temp1 - 1)) % MOD;
    long long sum = 0;

    for (int a = 0; a < N; a++)
        sum = (sum + C[a]) % MOD;

    for (int a = 0; a < N; a++) {
        long long ans = (C[a] * temp1 + ((sum - C[a] + MOD) % MOD) * temp2) % MOD;

        printf("%lld\n", ans);
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

#define MOD 98765431

typedef vector<vector<long long> > Matrix;

int K;
vector<long long> F1;
Matrix T;

// testing O(N^3 log(T))

Matrix multiply(const Matrix &x, const Matrix &y){
	Matrix ans(K + 1, vector<long long>(K + 1));

	for(int a = 1; a <= K; a++)
		for(int b = 1; b <= K; b++)
			for(int c = 1; c <= K; c++)
				ans[a][b] = (ans[a][b] + (x[a][c] * y[c][b]) % MOD) % MOD;

	return ans;
}

Matrix pow(const Matrix &x, long long p){
	if(p == 1)
		return x;
	if(p % 2)
		return multiply(x, pow(x, p - 1));

	Matrix squared = pow(x, p / 2);

	return multiply(squared, squared);
}

void f(long long x){
	T = pow(T, x);

	long long sum = 0;

	for(int a = 1; a <= K; a++){
		sum = 0;

		for(int b = 1; b <= K; b++)
			sum = (sum + T[a][b] * F1[b]) % MOD;
		
		printf("%lld\n", sum);
	}
}

int main(){
	long long times;

	scanf("%d %lld", &K, &times);

	F1.assign(K + 1, 0);
	T.assign(K + 1, vector<long long>(K + 1));

	for(int a = 1; a <= K; a++){
		scanf("%lld", &F1[a]);
		F1[a] %= MOD;
	}

	for(int a = 1; a <= K; a++)
		for(int b = 1; b <= K; b++)
			T[a][b] = 1;

	for(int a = 1; a <= K; a++)
		T[a][a] = 0;

	f(times);
}
*/