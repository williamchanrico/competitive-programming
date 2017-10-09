#include <bits/stdc++.h>
using namespace std;

class Pos{
public:
	int A, B, C;

	Pos(int A, int B, int C){
		this->A = A;
		this->B = B;
		this->C = C;
	}
};

int L, R, C;

bool validPos(int x, int y, int z){
	return (x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C);
}

int main(){
	int sA, sB, sC;
	char grid[40][40][40];

	while(scanf("%d %d %d", &L, &R, &C), (L | R | C)){

		for(int a = 0; a < L; a++){
			for(int b = 0; b < R; b++){
				scanf("%s", grid[a][b]);

				for(int c = 0; c < C; c++){
					if(grid[a][b][c] == 'S'){
						grid[a][b][c] = '#';
						sA = a;
						sB = b;
						sC = c;
					}
				}
			}
		}
	
		int dA[] = {0, 0, 0, 0, 1, -1};
		int dB[] = {0, 1, 0, -1, 0, 0};
		int dC[] = {1, 0, -1, 0, 0, 0};
		int dist[40][40][40], ans = -1;
		queue<Pos> q;

		q.push(Pos(sA, sB, sC));

		memset(dist, -1, sizeof(dist));

		dist[sA][sB][sC] = 0;

		while(!q.empty()){
			Pos front = q.front();

			q.pop();

			for(int a = 0; a < 6; a++){
				int nA = front.A + dA[a];
				int nB = front.B + dB[a];
				int nC = front.C + dC[a];

				if(validPos(nA, nB, nC) && grid[nA][nB][nC] != '#'){
					dist[nA][nB][nC] = dist[front.A][front.B][front.C] + 1;

					if(grid[nA][nB][nC] == 'E'){
						ans = dist[nA][nB][nC];

						break;
					}
					
					grid[nA][nB][nC] = '#';

					q.push(Pos(nA, nB, nC));
				}
			}

			if(ans != -1) break;
		}

		if(ans == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
}
