#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_V 50

int res[MAX_V][MAX_V], S, T, F, nodes = 0;
vector<int> p;

void augment(int u, int minEdge){
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

/*
	indexes:
		S: 0
		A-Z applications: 1 -> 26
		0-9 computers: 27 -> 36
		T: 37
*/

int main(){
	string inp;

	S = 0;
	T = 37;
	nodes = 38;

	while(getline(cin, inp)){
		int totalAppCount = 0;

		memset(res, 0, sizeof(res));

		do{
			int appIdx = inp[0] - 'A' + 1;
			int appCount = inp[1] - '0';

			res[S][appIdx] = appCount;
			totalAppCount += appCount;

			for(int a = 3; inp[a] != ';'; a++){
				int computerIdx = inp[a] - '0' + 27;

				res[appIdx][computerIdx] = INF;
				res[computerIdx][T] = 1;
			}

		}while(getline(cin, inp), inp != "");

		if(maxFlow() == totalAppCount){

			for(int computerIdx = 27; computerIdx <= 36; computerIdx++){
				bool computerAllocated = false;

				for(int appIdx = 1; appIdx <= 26 && !computerAllocated; appIdx++){
					if(res[computerIdx][appIdx] == 1){
						printf("%c", appIdx + 'A' - 1);

						computerAllocated = true;
					}
				}

				if(!computerAllocated)
					printf("_");
			}
		}else{

			printf("!");
		}

		printf("\n");
	}
}
