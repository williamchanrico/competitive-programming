#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

int main(){
	int T;

	scanf("%d", &T);

	for(int TC = 1; TC <= T; TC++){
		int N, M, S, target;

		scanf("%d %d %d %d", &N, &M, &S, &target);

		int A, B, W;
		vector<vector<pair<int, int> > > adjList(N);

		for(int a = 0; a < M; a++){
			scanf("%d %d %d", &A, &B, &W);

			adjList[A].push_back(make_pair(B, W));
			adjList[B].push_back(make_pair(A, W));
		}

		vector<int> dist(N, INF);
		priority_queue<pii, vector<pii>, greater<pii> > pq;

		dist[S] = 0;

		pq.push(make_pair(0, S));

		while(!pq.empty()){
			pii front = pq.top();

			pq.pop();

			int d = front.first;
			int u = front.second;

			if(d > dist[u]) continue;

			for(int a = 0; a < adjList[u].size(); a++){
				pair<int, int> v = adjList[u][a];

				if(dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;

					pq.push(make_pair(dist[v.first], v.first));
				}
			}
		}

		if(dist[target] == INF)
			printf("Case #%d: unreachable\n", TC);
		else
			printf("Case #%d: %d\n", TC, dist[target]);
	}
}
