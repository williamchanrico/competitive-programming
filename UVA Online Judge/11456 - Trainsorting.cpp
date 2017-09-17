#include <bits/stdc++.h>
using namespace std;

int N, memoLis[2100], memoLds[2100];
vector<int> v(2100);

void dpLis(){
	for(int a = N - 1; a >= 0; a--){
		memoLis[a] = 1;

		for(int b = a + 1; b < N; b++)
			if(v[a] < v[b])
				memoLis[a] = max(memoLis[a], 1 + memoLis[b]);
	}
}

void dpLds(){
	for(int a = N - 1; a >= 0; a--){
		memoLds[a] = 1;

		for(int b = a + 1; b < N; b++)
			if(v[a] > v[b])
				memoLds[a] = max(memoLds[a], 1 + memoLds[b]);
	}
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);

		for(int a = 0; a < N; a++)
			scanf("%d", &v[a]);

		dpLis();
		dpLds();

		int ans = 0;

		for(int a = 0; a < N; a++)
			ans = max(ans, memoLis[a] + memoLds[a] - 1);

		printf("%d\n", ans);
	}
}