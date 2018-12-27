#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;

    while (scanf("%d %d", &M, &N) != EOF) {

        vector<vector<pair<int, int>>> v(M), ans(N);

        for (int a = 0; a < M; a++) {
            int R;

            scanf("%d", &R);

            vector<int> vRow(R);

            for (int b = 0; b < R; b++)
                scanf("%d", &vRow[b]);

            int val;

            for (int b = 0; b < R; b++) {
                scanf("%d", &val);

                v[a].push_back(make_pair(vRow[b], val));
            }
        }

        for (int a = 0; a < M; a++) {
            for (int b = 0; b < v[a].size(); b++) {
                pair<int, int> u = v[a][b];

                ans[u.first - 1].push_back(make_pair(a + 1, u.second));
            }
        }

        printf("%d %d\n", N, M);

        for (int a = 0; a < N; a++) {
            printf("%d", ans[a].size());

            for (int b = 0; b < ans[a].size(); b++)
                printf(" %d", ans[a][b].first);

            printf("\n");

            for (int b = 0; b < ans[a].size(); b++) {
                if (b)
                    printf(" ");

                printf("%d", ans[a][b].second);
            }

            printf("\n");
        }
    }
}

/* noob's way of constructing the ans

		for(int a = 0; a < N; a++){

			for(int b = 0; b < M; b++){
				int idx = -1;

				for(int c = 0; c < v[b].size() && v[b][c].first <= a + 1; c++){
					if(v[b][c].first == a + 1){
						idx = c;
						break;
					}
				}

				if(idx != -1)
					ans[a].push_back(make_pair(b + 1, v[b][idx].second));
			}
		}

*/