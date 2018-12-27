#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);

    while (N--) {
        char str[110];

        scanf("%s", str);

        int len = strlen(str);

        if (len > 10)
            printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
        else
            printf("%s\n", str);
    }
}