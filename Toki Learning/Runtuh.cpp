#include <bits/stdc++.h>
using namespace std;

int R, C;
char grid[30][10];

int hilang(){
    int last = -1;

    for(int a = last + 1; a < R; a++){
        bool full = true;

        for(int b = 0; b < C; b++)
            if(grid[a][b] == '0')
                full = false;

        if(full){
            last = a;

            for(int b = 0; b < C; b++)
                grid[a][b] = '0';
        }
    }

    return last;
}

void runtuh(int last){
    for(int a = last - 1; a >= 0; a--){
        for(int b =  0; b < C; b++){
            if(grid[a][b] == '1'){
                
                grid[a][b] = '0';

                int idx = a;

                while(idx < R && grid[idx][b] == '0')
                    idx++;

                grid[idx - 1][b] = '1';
            }
        }
    }
}

int main(){
    scanf("%d %d", &R, &C);

    for(int a = 0; a < R; a++)
        scanf("%s", grid[a]);

    int last = -1;

    while((last = hilang()) != -1)
        runtuh(last);

    for(int a = 0; a < R; a++)
        printf("%s\n", grid[a]);
}