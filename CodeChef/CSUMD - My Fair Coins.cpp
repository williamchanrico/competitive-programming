#include <bits/stdc++.h>
using namespace std;

#define MAX_STATE 25

int K, MOD = 1000000007;

class Matrix {
public:
    int row, col, val[MAX_STATE][MAX_STATE];

    Matrix() {}

    Matrix(int row, int col, int diagonalValue = 0)
    {
        memset(val, 0, sizeof(val));

        this->row = row;
        this->col = col;

        for (int a = 0; a < row; a++)
            val[a][a] = diagonalValue;
    }

    Matrix operator*(const Matrix& x) const
    {
        Matrix ans(row, x.col);

        for (int a = 0; a < row; a++) {
            for (int b = 0; b < x.row; b++) {
                long long temp = 0;

                for (int c = 0; c < col; c++) {
                    temp += ((long long)val[a][c] * x.val[c][b]) % MOD;
                }

                ans.val[a][b] = temp % MOD;
            }
        }

        return ans;
    }

    Matrix operator^(long long x) const
    {
        Matrix curr = *this;
        Matrix ans(row, col, 1);

        while (x) {
            if (x & 1)
                ans = ans * curr;
            x >>= 1;
            curr = curr * curr;
        }

        return ans;
    }

    void print()
    {
        printf("=====\n");
        for (int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++)
                printf("%d ", val[a][b]);
            printf("\n");
        }
        printf("=====\n");
    }
};

long long f(long long x)
{
    Matrix F(2, 1);

    F.val[0][0] = 1;
    F.val[1][0] = 3;

    Matrix T(2, 2);

    T.val[0][0] = 0;
    T.val[0][1] = 1;
    T.val[1][0] = 2;
    T.val[1][1] = 2;

    Matrix ans = (T ^ (x - 1)) * F;

    return ans.val[0][0];
}

int main()
{
    int TC;

    scanf("%d", &TC);

    while (TC--) {
        long long N;

        scanf("%lld", &N);

        printf("%lld\n", f(N));
    }
}

/*
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<vector<long long> > Matrix;
 
long long MOD = 1000000007, K = 3;
 
Matrix multiply(const Matrix &x, const Matrix &y){
	Matrix ans(K + 1, vector<long long>(K + 1));
 
	for(int a = 1; a <= K; a++)
		for(int b = 1; b <= K; b++)
			for(int c = 1; c <= K; c++)
				ans[a][b] = (ans[a][b] + x[a][c] * y[c][b]) % MOD;
 
	return ans;
}
 
Matrix pow(const Matrix &x, int p){
	if(p == 1)
		return x;
	if(p % 2)
		return multiply(x, pow(x, p - 1));
 
	Matrix squared = pow(x, p / 2);
 
	return multiply(squared, squared);
}
 
long long f(int x){
	vector<long long> F1(K + 1);
 
	F1[1] = 1;
	F1[2] = 3;
 
	Matrix T(K + 1, vector<long long>(K + 1));
	T[1][1] = 0, T[1][2] = 1;
	T[2][1] = 2, T[2][2] = 2;
 
	if(x <= 2)
		return F1[x] % MOD;
 
	T = pow(T, x - 1);
 
	long long ans = 0;
 
	for(int a = 1; a <= K; a++)
		ans = (ans + T[1][a] * F1[a]) % MOD;
 
	return ans;
}
 
int main(){
	int T, N;
 
	scanf("%d", &T);
 
	while(T--){
		scanf("%d", &N);
 
		printf("%lld\n", f(N));
	}
}
*/