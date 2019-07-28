#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp;

    getline(cin, inp);

    long long N;
    int input_len = inp.size();

    scanf("%lld", &N);

    int cummulative_a[110];
    cummulative_a[0] = 0;
    for (int a = 1; a <= input_len; a++) {
        cummulative_a[a] = cummulative_a[a - 1] + (inp[a - 1] == 'a' ? 1 : 0);
    }

    assert(input_len != 0);
    long long ans = (N / input_len * cummulative_a[input_len]);
    ans += (cummulative_a[(int)(N % input_len)]);
    printf("%lld\n", ans);
}
