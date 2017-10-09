#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, TC = 1;

	while(scanf("%d", &N), N){
		map<int, int> m;
		vector<vector<int> > adjList(40);
		int A, B, count = 0;

		while(N--){
			scanf("%d %d", &A, &B);

			if(!m.count(A))
				m[A] = count++;

			if(!m.count(B))
				m[B] = count++;

			adjList[m[A]].push_back(m[B]);
			adjList[m[B]].push_back(m[A]);
		}

		while(scanf("%d %d", &A, &B), (A | B)){
			queue<int> q;
			vector<int> dist(count, -1);

			int ans = count;

			if(m.count(A)){
				ans--;
			
				dist[m[A]] = 0;
			
				q.push(m[A]);
			}

			while(!q.empty()){
				int front = q.front();

				q.pop();

				for(int a = 0; a < adjList[front].size(); a++){
					int next = adjList[front][a];

					if(dist[next] == -1 && dist[front] + 1 <= B){
						ans--;

						dist[next] = dist[front] + 1;
						
						q.push(next);
					}
				}
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", 
				TC++, ans, A, B);
		}
	}
}
