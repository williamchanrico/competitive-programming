#include <bits/stdc++.h>
using namespace std;

int countSwap(vector<int>& v)
{
    int ans = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (size_t a = 0, len = v.size(); a < len - 1; ++a) {
            if (v[a] > v[a + 1]) {
                swap(v[a], v[a + 1]);
                sorted = false;
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    int N;

    scanf("%d", &N);

    vector<int> v(N);
    for (int a = 0; a < N; a++) {
        scanf("%d", &v[a]);
    }

    printf("Array is sorted in %d swaps.\n", countSwap(v));
    printf("First Element: %d\n", v[0]);
    printf("Last Element: %d\n", v[v.size() - 1]);
}
