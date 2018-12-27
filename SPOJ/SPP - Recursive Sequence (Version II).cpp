#include <bits/stdc++.h>
using namespace std;

#define MAX_STATE 25

int K, MOD;

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

/*
	example:
		K = 3
		B[] = 1 2 3
		C[] = 7 8 9

	F would be:
		1 <-- B[0]
		2 <-- B[1]
		3 <-- B[2]
		6 <-- sum of B[]
	
	T would be:
		0 1 0 0 <-- carry second-latest number to next iteration
		0 0 1 0 <-- carry latest number to next iteration
		9 8 7 0 <-- calculate the next number of the sequence and carry to next iteration
		9 8 7 1 <-- calculate the next cumulative sum and carry it over (this is the answer)
*/

long long f(long long x, const Matrix& T, const Matrix& F)
{
    if (x <= K) {
        long long ans = 0;

        for (int a = 0; a < x; a++)
            ans = (ans + F.val[a][0]) % MOD;

        return ans;
    }

    Matrix ans = (T ^ (x - K)) * F;

    return ans.val[K][0];
}

int main()
{
    int TC;

    scanf("%d", &TC);

    while (TC--) {
        scanf("%d", &K);

        Matrix F(K + 1, 1);

        for (int a = 0; a < K; a++) {
            scanf("%d", &F.val[a][0]);

            F.val[K][0] += F.val[a][0];
        }

        Matrix T(K + 1, K + 1);

        for (int a = 0; a < (K - 1); a++)
            T.val[a][a + 1] = 1;

        for (int a = K - 1; a >= 0; a--) {
            scanf("%d", &T.val[K - 1][a]);

            T.val[K][a] = T.val[K - 1][a];
        }

        T.val[K][K] = 1;

        long long M, N;

        scanf("%lld %lld %d", &M, &N, &MOD);

        long long ans = f(N, T, F) - f(M - 1, T, F);

        printf("%lld\n", (ans < 0 ? ans + MOD : ans));
    }
}
