#include <stdio.h>
#include <string.h>

char tData[101][101];
char Data[101][101];
int jmlData,
    xSize,
    ySize;
void inputTabel();
void inputData();

int main()
{

    scanf("%d%d", &xSize, &ySize);

    inputTabel();
    inputData();

    int x = 0, y = 0, p = 0;
    int len;

    for (int a = 0; a < jmlData; a++) {
        for (int b = 0; b < xSize; b++) {
            for (int c = 0; c < ySize; c++) {
                p = 0;
                if (Data[a][p] == tData[b][c]) {
                    len = strlen(Data[a]);
                    p = 0;
                    x = b;
                    y = c;
                    // cek ke kiri
                    while (y != -1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }

                        } else {
                            y = 0;
                        }
                        p++;
                        y--;
                    }
                    p = 0;
                    x = b;
                    y = c;
                    // cek ke kanan
                    while (y != ySize + 1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            y = ySize;
                        }
                        p++;
                        y++;
                    }
                    p = 0;
                    x = b;
                    y = c;
                    // cek ke atas
                    while (x != -1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = 0;
                        }
                        x--;
                        p++;
                    }

                    p = 0;
                    x = b;
                    y = c;
                    // cek ke bawah
                    while (x != xSize + 1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = xSize;
                        }
                        x++;
                        p++;
                    }

                    p = 0;
                    x = b;
                    y = c;
                    // cek kiri atas
                    while (x != -1 && y != -1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = 0;
                        }
                        x--;
                        y--;
                        p++;
                    }
                    p = 0;
                    x = b;
                    y = c;
                    // cek kiri bawah
                    while (x != xSize + 1 && y != -1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = xSize;
                        }
                        x++;
                        y--;
                        p++;
                    }
                    p = 0;
                    x = b;
                    y = c;
                    // cek kanan atas
                    while (x != -1 && y != ySize + 1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = 0;
                        }
                        x--;
                        y++;
                        p++;
                    }
                    p = 0;
                    x = b;
                    y = c;
                    // cek kanan bawah
                    while (x != xSize + 1 && y != ySize + 1 && p < len) {
                        if (Data[a][p] == tData[x][y]) {
                            if ((p + 1) == len) {
                                printf("%s Y\n", Data[a]);
                                goto stops;
                            }
                        } else {
                            x = xSize;
                        }
                        x++;
                        y++;
                        p++;
                    }
                }
            }
        }
        printf("%s T\n", Data[a]);
    stops:
        p = 0;
    }
}

void inputTabel()
{
    getchar();
    for (int a = 0; a < xSize; a++) {
        for (int b = 0; b < ySize; b++) {
            scanf("%c", &tData[a][b]);
            getchar();
        }
    }
}

void inputData()
{
    scanf("%d", &jmlData);
    for (int a = 0; a < jmlData; a++) {
        scanf("%s", Data[a]);
    }
}
