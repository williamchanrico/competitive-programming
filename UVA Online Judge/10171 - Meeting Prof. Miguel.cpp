#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int N;

    while (scanf("%d", &N), N) {
        getchar();

        char age, type, A, B;
        int cost, adjMatY[30][30], adjMatM[30][30];

        memset(adjMatY, INF, sizeof(adjMatY));
        memset(adjMatM, INF, sizeof(adjMatM));

        for (int a = 0; a < N; a++) {
            scanf("%c %c %c %c %d", &age, &type, &A, &B, &cost);
            getchar();

            if (age == 'Y') {

                if (type == 'B')
                    adjMatY[A - 'A'][B - 'A'] = adjMatY[B - 'A'][A - 'A'] = cost;
                else
                    adjMatY[A - 'A'][B - 'A'] = cost;
            } else {

                if (type == 'B')
                    adjMatM[A - 'A'][B - 'A'] = adjMatM[B - 'A'][A - 'A'] = cost;
                else
                    adjMatM[A - 'A'][B - 'A'] = cost;
            }
        }

        scanf("%c %c", &A, &B);

        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                for (int c = 0; c < 26; c++) {
                    adjMatY[b][c] = min(adjMatY[b][c], adjMatY[b][a] + adjMatY[a][c]);
                    adjMatM[b][c] = min(adjMatM[b][c], adjMatM[b][a] + adjMatM[a][c]);
                }
            }
        }

        vector<pair<int, int>> ans;

        for (int a = 0; a < 26; a++) {
            adjMatY[a][a] = adjMatM[a][a] = 0;

            if (adjMatY[A - 'A'][a] != INF && adjMatM[B - 'A'][a] != INF) {
                ans.push_back(make_pair(adjMatY[A - 'A'][a] + adjMatM[B - 'A'][a], a));
            }
        }

        sort(ans.begin(), ans.end());

        if (ans.size()) {
            cost = ans[0].first;

            printf("%d", cost);

            for (int a = 0; a < ans.size(); a++)
                if (cost == ans[a].first)
                    printf(" %c", ans[a].second + 'A');

            printf("\n");

        } else {
            printf("You will never meet.\n");
        }
    }
}
