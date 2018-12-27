#include <map>
#include <stdio.h>
using namespace std;

map<int, int> m;
int inp, ans = -1, ansNum;

int main()
{
    scanf("%d", &inp);
    for (int a = inp; a > 0; a--) {
        scanf("%d", &inp);
        m[inp]++;
        if (m[inp] > ans) {
            ans = m[inp];
            ansNum = inp;
        } else if (m[inp] == ans) {
            ansNum = (ansNum < inp) ? inp : ansNum;
        }
    }
    printf("%d\n", ansNum);
}
