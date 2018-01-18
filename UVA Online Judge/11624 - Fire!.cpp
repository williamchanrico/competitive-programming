#include <bits/stdc++.h>
using namespace std;

char grid[1100][1100];
int R, C, joeGrid[1100][1100], fireGrid[1100][1100];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

typedef struct Point{
	int X;
	int Y;
} Point;

bool validPoint(Point x){
	return (x.X >= 0 && x.X < R && x.Y >= 0 && x.Y < C);
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		Point joe, fire;
		bool joeFreakingSurvivedTheFireOfDeath = false;

		memset(joeGrid, 0, sizeof(joeGrid));
		memset(fireGrid, 0, sizeof(fireGrid));
		
		scanf("%d %d", &R, &C);

		fire.X = fire.Y = -1;

		for(int a = 0; a < R; a++){
			scanf("%s", grid[a]);

			for(int b = 0; b < C; b++){
				if(grid[a][b] == 'J'){
					joe.X = a;
					joe.Y = b;
				}
			}
		}

		queue<Point> q;

		for(int a = 0; a < R; a++){
			for(int b = 0; b < C; b++){
				if(grid[a][b] == 'F'){
					fire.X = a;
					fire.Y = b;

					q.push(fire);

					fireGrid[a][b] = 1;
				}
			}
		}

		while(!q.empty()){
			Point u = q.front();

			q.pop();

			for(int a = 0; a < 4; a++){
				Point v;
				v.X = u.X + dx[a];
				v.Y = u.Y + dy[a];

				if(validPoint(v) && grid[v.X][v.Y] != '#' && fireGrid[v.X][v.Y] == 0){
					q.push(v);

					fireGrid[v.X][v.Y] = fireGrid[u.X][u.Y] + 1;
				}
			}
		}

		q.push(joe);

		joeGrid[joe.X][joe.Y] = 1;

		while(!q.empty()){
			Point u = q.front();

			q.pop();

			if(u.X == 0 || u.X == R - 1 || u.Y == 0 || u.Y == C - 1){
				printf("%d\n", joeGrid[u.X][u.Y]);

				joeFreakingSurvivedTheFireOfDeath = true;

				break;
			}

			for(int a = 0; a < 4; a++){
				Point v;
				v.X = u.X + dx[a];
				v.Y = u.Y + dy[a];

				if(validPoint(v) && grid[v.X][v.Y] != '#' && joeGrid[v.X][v.Y] == 0){
					if(joeGrid[u.X][u.Y] + 1 < fireGrid[v.X][v.Y] || fireGrid[v.X][v.Y] == 0){
						q.push(v);

						joeGrid[v.X][v.Y] = joeGrid[u.X][u.Y] + 1;
					}
				}
			}
		}

		if(!joeFreakingSurvivedTheFireOfDeath)
			printf("IMPOSSIBLE\n");
	}
}
