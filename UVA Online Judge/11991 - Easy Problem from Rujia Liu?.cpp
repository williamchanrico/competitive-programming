#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;

	while(scanf("%d %d", &N, &M) != EOF){
		int K, inp;
		vector<vector<int> > v(1100000);

		for(int a = 0; a < N; a++){
			scanf("%d", &inp);

			v[inp].push_back(a + 1);
		}

		for(int a = 0; a < M; a++){
			scanf("%d %d", &K, &N);

			if(v[N].size() < K)
				printf("0\n");
			else
				printf("%d\n", v[N][K - 1]);
		}
	}
}