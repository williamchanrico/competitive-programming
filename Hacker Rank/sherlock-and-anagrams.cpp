#include <bits/stdc++.h>
using namespace std;

int is_anagram(char* x, char* y)
{
    char xx[27] = { 0 }, yy[27] = { 0 };

    for (size_t a = 0, len = strlen(x); a < len; a++) {
        ++xx[x[a] - 'a'];
        ++yy[y[a] - 'a'];
    }

    for (size_t a = 0; a < 26; a++)
        if (xx[a] != yy[a])
            return 0;
    return 1;
}

int main()
{
    int Q;

    scanf("%d", &Q);

    char s[110];
    while (Q--) {
        scanf("%s", s);

        int ans = 0;
        int inp_len = strlen(s);
        for (int curr_len = 1; curr_len <= (inp_len - 1); curr_len++) {

            for (int first_idx = 0; first_idx < inp_len; first_idx++) {

                for (int second_idx = first_idx + 1; second_idx < inp_len; second_idx++) {
                    if (first_idx == second_idx)
                        continue;
                    if (first_idx + curr_len > inp_len || second_idx + curr_len > inp_len)
                        continue;

                    char first_str[110], second_str[110];
                    strncpy(first_str, s + first_idx, curr_len);
                    first_str[curr_len] = '\0';
                    strncpy(second_str, s + second_idx, curr_len);
                    second_str[curr_len] = '\0';

                    ans += is_anagram(first_str, second_str);
                }
            }
        }
        printf("%d\n", ans);
    }
}
