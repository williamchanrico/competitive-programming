#include <bits/stdc++.h>
using namespace std;

long long nCk(long long N, long long K){
	if(K > N) return 0;
	if(K == 0) return 1;

	long long ans = 1;

	if(N < (2 * K))
		K = N - K;

	for(long long a = 0; a < K; a++){
		ans *= (N - a);
		ans /= (a + 1);
	}

	return ans;
}

int main(){
	int N, ans = 0;

	scanf("%d", &N);

	map<int, int> mPlus;
	map<int, int> mMin;
	while(N--){
		int X, Y;

		scanf("%d %d", &X, &Y);

		if(mPlus.count(X + Y)){
			mPlus[X + Y]++;
		}else{
			mPlus[X + Y] = 1;
		}

		if(mMin.count(X - Y)){
			mMin[X - Y]++;
		}else{
			mMin[X - Y] = 1;
		}
	}

	for(auto it = mPlus.begin(); it != mPlus.end(); it++)
		ans += nCk(it->second, 2);
	for(auto it = mMin.begin(); it != mMin.end(); it++)
		ans += nCk(it->second, 2);

	printf("%d\n", ans);
}
