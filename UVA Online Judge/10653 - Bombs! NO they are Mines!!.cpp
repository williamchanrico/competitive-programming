#include <bits/stdc++.h>
using namespace std;

int main(){
	int R, C;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	while(scanf("%d %d", &R, &C), (R | C)){
		int adjMat[1100][1100], bCount, sX, sY, dX, dY;

		memset(adjMat, -1, sizeof(adjMat));

		scanf("%d", &bCount);

		while(bCount--){
			int row, col, count;

			scanf("%d %d", &row, &count);

			for(int a = 0; a < count; a++){
				scanf("%d", &col);

				adjMat[row][col] = 0;
			}
		}

		scanf("%d %d %d %d", &sX, &sY, &dX, &dY);

		queue<pair<int, int> > q;

		adjMat[sX][sY] = 0;

		q.push(make_pair(sX, sY));
	
		while(!q.empty()){
			pair<int, int> u = q.front();

			q.pop();

			for(int a = 0; a < 4; a++){
				int X = u.first + dx[a];
				int Y = u.second + dy[a];

				if(X >= 0 && X < R && Y >= 0 && Y < C && adjMat[X][Y] == -1){
					adjMat[X][Y] = adjMat[u.first][u.second] + 1;

					q.push(make_pair(X, Y));
					
					if(X == dX && Y == dY){
						queue<pair<int, int> >().swap(q);

						break;
					}
				}
			}
		}

		printf("%d\n", adjMat[dX][dY]);
	}
}
