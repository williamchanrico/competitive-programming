#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
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

				ans.val[a][b] = temp;
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
};

/*
	f(N, arg1, arg2, arg3)
	arg1: total problems coded by 'Person V' modulo K 		[0 -> (K - 1)]
	arg2: whether 'Person J' coded N-th problem or not 		[0 or 1]
	arg3: wheter 'Person K' has coded any problem or not 	[0 or 1]

	in total there are (K * 2 * 2) states 					[0 -> ((K * 2 * 2) - 1)]

	states mapping
	f(N, arg1, arg2, arg3) => f(N, [0 -> (4K - 1)])

	Recurrence:
	f(N, arg1, arg2, arg3) =
		f(N - 1, arg1 - 1, arg2, arg3) +		<-- 'Person V' coded N-th problem

		f(N - 1, arg1, 1 - arg2, arg3) +		<-- 'Person J' coded N-th problem

		f(N - 1, arg1, arg2, 1 - arg3) +		<-- 'Person K' coded N-th problem
		f(N - 1, arg1, arg2, arg3)
*/
int main(){
	int TC;

	scanf("%d", &TC);

	while(TC--){
		long long N;
		int K;

		scanf("%lld %d", &N, &K);

		Matrix T((max(K, 1) * 2 * 2), (max(K, 1) * 2 * 2));

		int stateNum = 0, stateMap[20][5][5];

		memset(stateMap, 0, sizeof(stateMap));

		for(int a = 0; a < max(K, 1); a++)
			for(int b = 0; b < 2; b++)
				for(int c = 0; c < 2; c++)
					stateMap[a][b][c] = stateNum++;

		for(int a = 0; a < max(K, 1); a++){
			for(int b = 0; b < 2; b++){
				for(int c = 0; c < 2; c++){
					// f(N, state1)
					int state1 = stateMap[a][b][c];

					// f(N - 1, state where Person V did it and possible to reach f(N, state1))
					if(K)
						T.val[state1][stateMap[(a + 1) % K][0][c]]++;
					
					// f(N - 1, state where Person J did it and possible to reach f(N, state1))
					if(b == 0)
						T.val[state1][stateMap[a][1][c]]++;

					// f(N - 1, state where Person K did it and possible to reach f(N, state1))
					T.val[state1][stateMap[a][0][1]]++;
				}
			}
		}

		long long ans = 0;
		T = T ^ N;

		// sum all states where the conditions match:
		// arg1 must be zero (total solved is multiple of K)
		// arg2 may be true or false (may or may not be the one that solved the last problem)
		// arg3 must be true (at least have solved 1 problem in the end)
		for(int a = 0; a < 2; a++)
			ans = (ans + T.val[0][stateMap[0][a][1]]) % MOD;

		printf("%lld\n", ans);
	}
}
