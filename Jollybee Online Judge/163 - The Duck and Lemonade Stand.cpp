#include <bits/stdc++.h>
using namespace std;

int T, D, N, M, totalChecked, threat, temp;
map<int, int> mA;

int main()
{
    scanf("%d", &T);

    for (int a = 1; a <= T; a++) {
        totalChecked = 0;
        threat = 0;

        mA.clear();

        scanf("%d", &D);

        printf("Case #%d:\n", a);

        while (D--) {
            scanf("%d", &N);

            while (N--) {
                scanf("%d", &temp);

                if (!mA.count(temp))
                    mA[temp] = 0, threat++;
                else if (mA[temp] == -1)
                    mA[temp] = 1;
            }

            scanf("%d", &M);

            while (M--) {
                scanf("%d", &temp);

                if (!mA.count(temp))
                    mA[temp] = -1;
                else if (mA[temp] == 0)
                    mA[temp] = 1, totalChecked++;
            }

            printf("%s\n", (totalChecked == threat) ? "SAFE" : "ALERT");
        }
    }
}
