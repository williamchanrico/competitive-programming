#include <math.h>
#include <stdio.h>
using namespace std;

#define MOD 1000000

long long A, B, BASE, tesA, tesB;
bool lebih = false;

int main()
{
    scanf("%lld %lld", &A, &B);
    if (B == 0) {
        printf("1\n");
        return 0;
    }
    tesA = A;
    tesB = B;
    if (A > 999999)
        lebih = true;
    BASE = 1;
    while (B > 1) {
        if (B % 2 == 0) {
            A %= MOD;
            A = (A * A) % MOD;
            B /= 2;
        } else {
            A %= MOD;
            BASE *= A;
            BASE %= MOD;
            A = ((A * A) % MOD) % MOD;
            B /= 2;
        }
    }
    long long ans = (A * BASE) % MOD;
    long long basetesA = tesA;
    if (ans == 0) {
        printf("000000\n");
        return 0;
    }
    while (tesB > 1) {
        tesA *= basetesA;
        if (tesA > 999999) {
            lebih = true;
            break;
        }
        tesB--;
    }
    if (lebih) {
        long long temp = ans, count = 0;
        while (temp > 0) {
            count++;
            temp /= 10;
        }
        for (int a = 6 - count; a > 0; a--)
            printf("0");
        if (count != 0)
            printf("%lld\n", ans);
    } else {
        printf("%lld\n", ans);
    }
}