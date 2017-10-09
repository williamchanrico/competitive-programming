#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

int R, C, M, N, grid[210][210];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool validPos(int x, int y){
	return (x > 0 && x <= R && y > 0 && y <= C);
}

bool validDist(int x1, int y1, int x2, int y2, int z){
	int X = abs(x2 - x1) * abs(x2 - x1);
	int Y = abs(y2 - y1) * abs(y2 - y1);

	return ((X + Y) <= (z * z));
}

int main(){
	while(scanf("%d %d", &R, &C), (R | C)){
		int X, Y, Z;

		memset(grid, INF, sizeof(grid));

		scanf("%d", &M);

		while(M--){
			scanf("%d %d", &X, &Y);

			grid[X][Y] = -1;
		}

		scanf("%d", &N);

		while(N--){
			scanf("%d %d %d", &X, &Y, &Z);

			queue<pii> q;

			q.push(make_pair(X, Y));

			grid[X][Y] = N;

			while(!q.empty()){
				pii u = q.front();

				q.pop();

				for(int a = 0; a < 4; a++){
					int nX = u.first + dx[a];
					int nY = u.second + dy[a];

					if(validPos(nX, nY) && validDist(X, Y, nX, nY, Z) && grid[nX][nY] != N){
						grid[nX][nY] = N;

						q.push(make_pair(nX, nY));
					}
				}
			}
		}

		int ans = -1;
		queue<pii> q;

		q.push(make_pair(1, 1));

		grid[1][1] = 0;

		while(!q.empty()){
			pii u = q.front();

			q.pop();

			for(int a = 0; a < 4; a++){
				int nX = u.first + dx[a];
				int nY = u.second + dy[a];

				if(validPos(nX, nY) && grid[nX][nY] == INF){
					grid[nX][nY] = grid[u.first][u.second] + 1;

					if(nX == R && nY == C){
						ans = grid[nX][nY];

						break;
					}

					q.push(make_pair(nX, nY));
				}
			}

			if(ans != -1) break;
		}

		if(ans == -1)
			printf("Impossible.\n");
		else
			printf("%d\n", ans);
	}
}
