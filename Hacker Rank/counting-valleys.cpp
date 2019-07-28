#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);
    getchar();

    char step;
    int state = 0, ans = 0;
    while ((step = getchar()) != '\n' && step != EOF) {
        assert(step == 'U' || step == 'D');

        state += (step == 'D' ? -1 : 1);
        ans += (state == 0 ? (step == 'U' ? 1 : 0) : 0);
    }
    printf("%d\n", ans);
}
