#include <bits/stdc++.h>
using namespace std;

int main()
{

    auto lenA = 0;
    auto lenB = 0;
    auto lenC = 0;

    scanf("%d %d %d", &lenA, &lenB, &lenC);

    int A[lenA], B[lenB], C[lenC];
    for (int a = 0; a < lenA; a++)
        scanf("%d", &A[a]);
    for (int a = 0; a < lenB; a++)
        scanf("%d", &B[a]);
    for (int a = 0; a < lenC; a++)
        scanf("%d", &C[a]);

    auto setA = set<int>(A, A + lenA);
    auto setB = set<int>(B, B + lenB);
    auto setC = set<int>(C, C + lenC);

    auto vA = vector<int>(setA.begin(), setA.end());
    auto vB = vector<int>(setB.begin(), setB.end());
    auto vC = vector<int>(setC.begin(), setC.end());
    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());
    sort(vC.begin(), vC.end());

    size_t idxA = 0;
    size_t idxB = 0;
    size_t idxC = 0;

    long long ans = 0;
    while (idxB < vB.size()) {
        while (idxA < vA.size() && vA[idxA] <= vB[idxB])
            ++idxA;
        while (idxC < vC.size() && vC[idxC] <= vB[idxB])
            ++idxC;

        ans += (idxA * idxC);
        ++idxB;
    }
    printf("%lld\n", ans);
}
