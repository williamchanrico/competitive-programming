#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

char dictionary[25500][20];
int wordslen[25500];
int idxInput = 0;
vector<int> p;
vector<vector<int>> AdjList(25200, vector<int>());
bitset<25500> explore;

bool isDoublets(char x[], int xLen, char y[], int yLen)
{
    int diffLimit = 1;

    if (xLen != yLen)
        return false;

    for (int a = 0; a < xLen; a++) {
        if (x[a] != y[a]) {
            --diffLimit;
            if (diffLimit < 0)
                return false;
        }
    }
    return true;
}

void printPath(int x, int y)
{
    if (y == x) {
        printf("%s\n", dictionary[y]);
        return;
    }

    printPath(x, p[y]);

    printf("%s\n", dictionary[y]);
}

void bfs(int idxS, int idxE)
{
    queue<int> q;

    q.push(idxS);
    explore.set();
    explore[idxS] = false;
    p.assign(idxInput, -1);

    while (!q.empty()) {
        int u = q.front();

        q.pop();

        for (int a = 0; a < AdjList[u].size(); a++) {
            int target = AdjList[u][a];
            if (explore[target]) {
                explore[target] = false;
                p[target] = u;
                q.push(target);
                if (target == idxE)
                    return;
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (scanf("%s", dictionary[idxInput]), cin.ignore(), cin.peek() != '\n') {
        wordslen[idxInput] = strlen(dictionary[idxInput]);

        for (int a = 0; a < idxInput; a++) {
            if (isDoublets(dictionary[idxInput], wordslen[idxInput], dictionary[a], wordslen[a])) {
                AdjList[a].push_back(idxInput);
                AdjList[idxInput].push_back(a);
            }
        }
        ++idxInput;
    }

    char S[20], E[20];
    bool extraLine = false;

    while (scanf("%s %s", S, E) != EOF) {
        int idxS = -1, idxE = -1;

        for (int a = 0, len = idxInput; a < len; a++) {
            if (strcmp(dictionary[a], S) == 0)
                idxS = a;
            if (strcmp(dictionary[a], E) == 0)
                idxE = a;
            if (idxS != -1 && idxE != -1)
                break;
        }

        if (extraLine)
            printf("\n");

        extraLine = true;

        if (strlen(S) != strlen(E) || idxS == -1 || idxE == -1) {
            printf("No solution.\n");
            continue;
        }

        bfs(idxS, idxE);

        if (explore[idxE] == false)
            printPath(idxS, idxE);
        else
            printf("No solution.\n");
    }
}
