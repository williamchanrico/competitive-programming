#include <stdio.h>

int n;

void TulisJawaban(int& x)
{
    int ans = 0;
    while (x > 0)
        x /= 10, ans++;
    switch (ans) {
    case 1:
        puts("satuan");
        break;
    case 2:
        puts("puluhan");
        break;
    case 3:
        puts("ratusan");
        break;
    case 4:
        puts("ribuan");
        break;
    case 5:
        puts("puluhribuan");
        break;
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
        TulisJawaban(n);
}
