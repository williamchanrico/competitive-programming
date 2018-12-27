#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

map<string, int> m;
int n;
char inp[35];

int main()
{
    scanf("%d", &n);
    while (n--) {
        scanf("%s", inp);
        if (m.count(inp))
            printf("%s%d\n", inp, ++m[inp]);
        else {
            m[inp] = 0;
            printf("OK\n");
        }
    }
}
