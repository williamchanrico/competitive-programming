#include <stdio.h>
#include <string.h>

int main()
{

    char name[50];

    scanf("%s", name);
    printf("\n\n");
    for (int a = 0; a < strlen(name); a++) {
        printf("%c", name[a]);
    }
    printf("\n");
    for (int a = 1; a < strlen(name) - 1; a++) {
        printf("%c", name[a]);
        for (int b = 0; b < strlen(name) - 2; b++) {
            printf(" ");
        }
        printf("%c", name[strlen(name) - 1 - a]);
        printf("\n");
    }

    for (int a = strlen(name) - 1; a >= 0; a--)
        printf("%c", name[a]);
}