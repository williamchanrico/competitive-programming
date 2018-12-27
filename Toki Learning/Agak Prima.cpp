#include <stdio.h>

int T, ans = 0, inp;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &inp);
        if (inp < 1)
            printf("TIDAK\n");
        else
            for (int a = 1; a <= inp; a++) {
                if (inp % a == 0)
                    ans++;
                if (ans > 4)
                    printf("TIDAK\n"), a = inp + 1;
                else if (ans < 5 && a == inp)
                    printf("YA\n");
            }
        ans = 0;
    }
}
