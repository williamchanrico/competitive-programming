#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int main(){
	// freopen("in.txt", "r", stdin);
	int N;
	
	scanf("%d", &N);

	for(int counter = 1; counter <= N; counter++){
		int n, m, S, T;
		
		scanf("%d %d %d %d", &n, &m, &S, &T);

		vector<vector<pair<int, int> > > AdjList(n);

		for(int a = 0; a < m; a++){
			int inp1, inp2, inp3;

			scanf("%d %d %d", &inp1, &inp2, &inp3);

			AdjList[inp1].push_back(make_pair(inp2, inp3));
			AdjList[inp2].push_back(make_pair(inp1, inp3));
		}

		vector<int> dist(n, INF);
		
		dist[S] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		pq.push(make_pair(0, S));

		while(!pq.empty()){
			int d = pq.top().first;
			int u = pq.top().second;

			pq.pop();

			if(dist[u] < d) continue;

			for(int a = 0; a < AdjList[u].size(); a++){
				pair<int, int> target = AdjList[u][a];
				
				if(dist[u] + target.second < dist[target.first]){
					dist[target.first] = dist[u] + target.second;
					pq.push(make_pair(dist[target.first], target.first));
				}
			}
		}

		if(dist[T] != INF){
			printf("Case #%d: %d\n", counter, dist[T]);
		}else{
			printf("Case #%d: unreachable\n", counter);
		}
	}
}