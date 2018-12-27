#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nInput;
    vector<int> v;

    while (scanf("%d", &nInput), nInput != 0) {
        vector<int> v(nInput);

        for (int a = 0; a < nInput; a++)
            scanf("%d", &v[a]);

        sort(v.begin(), v.end());

        printf("%d", v[0]);

        for (int a = 1; a < nInput; a++)
            printf(" %d", v[a]);

        printf("\n");
    }
}