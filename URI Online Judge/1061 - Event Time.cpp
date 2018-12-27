#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sH, sM, sS, sD, fH, fM, fS, fD;
    scanf("Dia %d", &sD);
    scanf("%d : %d : %d", &sH, &sM, &sS);
    getchar();
    scanf("Dia %d", &fD);
    scanf("%d : %d : %d", &fH, &fM, &fS);
    int totStart = sS, totFinish = fS, ans = 0;
    totStart += (sM * 60);
    totStart += (sH * 3600);
    totStart += (sD * 86400);
    totFinish += (fM * 60);
    totFinish += (fH * 3600);
    totFinish += (fD * 86400);
    ans = totFinish - totStart;
    int n = 0;
    if (ans >= 86400) {
        n += (ans / 86400);
        ans -= (86400 * n);
    }
    cout << n << " dia(s)\n";
    n = 0;
    if (ans >= 3600) {
        n += (ans / 3600);
        ans -= (3600 * n);
    }
    cout << n << " hora(s)\n";
    n = 0;
    if (ans >= 60) {
        n += (ans / 60);
        ans -= (60 * n);
    }
    cout << n << " minuto(s)\n";
    cout << ans << " segundo(s)\n";
}