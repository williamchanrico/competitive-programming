#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList(30);
bitset<30> visited;

void dfs(int u)
{
    if (!visited[u]) {
        visited[u] = 1;

        for_each(adjList[u].begin(), adjList[u].end(), dfs);
    }
}

int main()
{
    int T;

    scanf("%d", &T);

    while (T--) {
        char str[100];
        int tree = 0, acorn = 0;

        for (int a = 0; a < 30; a++)
            adjList[a].clear();

        visited.reset();

        while (scanf("%s", str), str[0] != '*') {
            adjList[str[1] - 'A'].push_back(str[3] - 'A');
            adjList[str[3] - 'A'].push_back(str[1] - 'A');
        }

        scanf("%s", str);

        for (int a = 0, len = strlen(str); a < len; a += 2) {
            int u = str[a] - 'A';

            if (!visited[u]) {

                if (adjList[u].size() == 0) {
                    acorn++;
                } else {
                    tree++;
                    dfs(u);
                }
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
}

/* BFS

void bfs(int start){
	queue<int> q;

	q.push(start);

	visited[start] = 1;

	while(!q.empty()){
		int u = q.front();

		q.pop();

		for(auto a : adjList[u]){

			if(!visited[a]){
				q.push(a);

				visited[a] = 1;
			}
		}
	}
}

*/