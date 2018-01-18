#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_V 1100

long long res[MAX_V][MAX_V];
int S, T, F, nodes = 0;
vector<int> p;

void augment(int u, long long minEdge){
    if(u == S){
        F = minEdge;
 
        return;
 
    }else if(p[u] != -1){
        augment(p[u], min(minEdge, res[p[u]][u]));
 
        res[p[u]][u] -= F;
        res[u][p[u]] += F;
    }
}

int maxFlow(){
    int maxF = 0;
 
    while(true){
        vector<int> dist(nodes, INF);
        queue<int> q;
 
        dist[S] = 0;
        q.push(S);
        p.assign(nodes, -1);
 
        while(!q.empty()){
            int u = q.front();
 
            q.pop();
 
            if(u == T) break;
 
            for(int a = 0; a < nodes; a++){
                if(res[u][a] > 0 && dist[a] == INF){
                    dist[a] = dist[u] + 1;
                    q.push(a);
                    p[a] = u;
                }
            }
        }
 
        F = 0;
 
        augment(T, INF);
 
        if(F == 0) break;
 
        maxF += F;
    }
 
    return maxF;
}

int main(){
    int N, M, K;

    while(scanf("%d %d", &N, &M) != EOF){
        memset(res, 0, sizeof(res));

        S = 0;
        T = N + M + 1;
        nodes = N + M + 2;

        for(int a = 1; a <= N; a++)
            res[S][a] = 1;

        for(int a = N + 1; a <= (N + M); a++)
            res[a][T] = 1;

        for(int a = 1; a <= N; a++){
            scanf("%d", &K);

            while(K--){
                int inp;

                scanf("%d", &inp);

                res[a][inp + N] = 1;
            }
        }

        printf("%d\n", maxFlow());
    }
}
