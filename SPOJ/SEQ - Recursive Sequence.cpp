#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
#define MAX_STATE 100

class Matrix{
public:
	int row, col, val[MAX_STATE][MAX_STATE];

	Matrix(){}

	Matrix(int row, int col, int diagonalValue = 0){
		memset(val, 0, sizeof(val));

		this->row = row;
		this->col = col;

		for(int a = 0; a < row; a++)
			val[a][a] = diagonalValue;
	}

	Matrix operator*(const Matrix &x) const{
		Matrix ans(row, x.col);

		for(int a = 0; a < row; a++){
			for(int b = 0; b < x.row; b++){
				long long temp = 0;

				for(int c = 0; c < col; c++){
					temp += ((long long) val[a][c] * x.val[c][b]) % MOD;
				}

				ans.val[a][b] = temp % MOD;
			}
		}

		return ans;
	}

	Matrix operator^(long long x) const{
		Matrix curr = *this;
		Matrix ans(row, col, 1);

		while(x){
			if(x & 1)
				ans = ans * curr;
			x >>= 1;
			curr = curr * curr;
		}

		return ans;
	}

	void print(){
		printf("=====\n");
		for(int a = 0; a < row; a++){
			for(int b = 0; b < col; b++)
				printf("%d ", val[a][b]);
			printf("\n");
		}
		printf("=====\n");
	}
};

int main(){
	int TC;

	scanf("%d", &TC);

	while(TC--){
		int N, K;

		scanf("%d", &K);

		Matrix F(K, 1);

		for(int a = 0; a < K; a++)
			scanf("%d", &F.val[a][0]);

		Matrix T(K, K);

		for(int a = 0; a < (K - 1); a++)
			T.val[a][a + 1] = 1;

		for(int a = K - 1; a >= 0; a--)
			scanf("%d", &T.val[K - 1][a]);

		scanf("%d", &N);

		Matrix ans = (T ^ (N - 1)) * F;

		printf("%d\n", ans.val[0][0]);
	}
}


/*
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000

typedef vector<vector<long long> > Matrix;

int K;
vector<long long> F1;
Matrix T;

Matrix multiply(const Matrix &x, const Matrix &y){
	Matrix ans(K + 1, vector<long long>(K + 1));

	for(int a = 1; a <= K; a++)
		for(int b = 1; b <= K; b++)
			for(int c = 1; c <= K; c++)
				ans[a][b] = (ans[a][b] + x[a][c] * y[c][b]) % MOD;

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

long long f(long long x){
	if(x <= K)
		return F1[x] % MOD;

	T = pow(T, x - 1);

	long long ans = 0;

	for(int a = 1; a <= K; a++)
		ans = (ans + T[1][a] * F1[a]) % MOD;

	return ans;
}

int main(){
	int TC;

	scanf("%d", &TC);

	while(TC--){
		long long N;

		scanf("%d", &K);

		F1.assign(K + 1, 0);
		T.assign(K + 1, vector<long long>(K + 1));

		for(int a = 1; a <= K; a++)
			scanf("%lld", &F1[a]);

		for(int a = 1; a <= (K - 1); a++)
			T[a][a + 1] = 1;

		for(int a = K; a >= 1; a--)
			scanf("%lld", &T[K][a]);
		
		scanf("%lld", &N);

		printf("%lld\n", f(N));
	}
}
*/