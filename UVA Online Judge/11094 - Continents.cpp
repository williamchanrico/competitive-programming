#include <bits/stdc++.h>
using namespace std;

int M, N, grid[50][50], water, land;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int mod(int x, int y){ return (x % y + y) % y; }

int bfs(int x, int y){
	int ans = 0;
	queue<pair<int, int> > q;

	q.push(make_pair(x, y));

	grid[x][y] = 1;

	while(!q.empty()){
		ans++;

		pair<int, int> u = q.front();

		q.pop();

		for(int a = 0; a < 4; a++){
			int X = u.first + dx[a];
			int Y = u.second + dy[a];

			if(X >= 0 && X < M && Y >= -N && Y < 2 * N && grid[X][mod(Y, N)] == land){
				grid[X][mod(Y, N)] = grid[u.first][u.second] + 1;

				q.push(make_pair(X, mod(Y, N)));
			}
		}
	}

	return ans;
}

int main(){
	while(scanf("%d %d", &M, &N) != EOF){
		char inp[50], firstInp;

		water = -1;
		land = 0;

		for(int a = 0; a < M; a++){
			scanf("%s", inp);

			if(a == 0)
				firstInp = inp[0];

			for(int b = 0; b < N; b++){
				if(inp[b] == firstInp)
					grid[a][b] = water;
				else
					grid[a][b] = land;
			}
		}

		int X, Y, ans = 0;

		scanf("%d %d", &X, &Y);

		if(grid[X][Y] == -1)
			swap(water, land);

		bfs(X, Y);

		for(int a = 0; a < M; a++)
			for(int b = 0; b < N; b++)
				if(grid[a][b] == land)
					ans = max(ans, bfs(a, b));

		printf("%d\n", ans);
	}
}