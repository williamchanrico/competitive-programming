#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;

    scanf("%d", &T);
    getchar();

    while (T--) {
        char str[210];
        int freq[30], maxi = -1;

        memset(freq, 0, sizeof(freq));

        fgets(str, 210, stdin);

        for (int a = 0, len = strlen(str); a < len; a++) {
            if (isalpha(str[a])) {
                str[a] = tolower(str[a]);

                freq[str[a] - 'a']++;
            }
        }

        for (int a = 0; a < 26; a++)
            maxi = max(maxi, freq[a]);

        for (int a = 0; a < 26; a++)
            if (freq[a] == maxi)
                printf("%c", a + 'a');

        printf("\n");
    }
}
