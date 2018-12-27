#include <stdio.h>

int n, inp, temp;
int ruble[5], rublecost[5];
bool gagal = false;

int main()
{
    ruble[0] = ruble[1] = ruble[2] = 0;
    rublecost[0] = 25, rublecost[1] = 50, rublecost[2] = 100;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &inp);
        if (!gagal)
            if (inp > 25) {
                if (inp == 50)
                    ruble[1]++;
                else
                    ruble[2]++;
                temp = inp - 25;
                for (int a = 2; a > -1; a--)
                    while (ruble[a] > 0 && rublecost[a] <= temp) {
                        temp -= rublecost[a];
                        ruble[a]--;
                    }
                if (temp != 0)
                    gagal = true;
            } else {
                ruble[0]++;
            }
    }
    if (gagal)
        printf("NO\n");
    else
        printf("YES\n");
}