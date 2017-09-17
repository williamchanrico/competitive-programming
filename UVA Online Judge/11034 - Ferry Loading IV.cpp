#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int L, M;

		scanf("%d %d", &L, &M);

		L *= 100;

		queue<int> q[2];

		while(M--){
			int inp, pos;
			char bank[10];

			scanf("%d %s", &inp, bank);

			pos = (bank[0] == 'l' ? 0 : 1);

			q[pos].push(inp);
		}

		int ans = 0, pos = 0;

		while(!q[0].empty() || !q[1].empty()){
			int sum = 0;

			while(!q[pos].empty() && sum + q[pos].front() <= L){
				sum += q[pos].front();
				q[pos].pop();
			}

			ans++;
			pos = ans % 2;
		}

		printf("%d\n", ans);
	}
}
