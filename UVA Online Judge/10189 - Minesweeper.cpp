#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[110][110];
int dx[] = {-1, 0, -1, 1, 0, 1, -1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, -1};

int check(int x, int y){
	int ans = 0;

	if(grid[x][y] == '*')
		return -1;

	for(int a = 0; a < 8; a++){
		int row = x + dx[a];
		int col = y + dy[a];

		if(row >= 0 && row < N && col >= 0 && col < M)
			if(grid[row][col] == '*')
				ans++;
	}

	return ans;
}

int main(){
	int T = 1;

	while(scanf("%d %d", &N, &M), (N | M)){

		for(int a = 0; a < N; a++)
			scanf("%s", grid[a]);

		int ans[110][110];

		for(int a = 0; a < N; a++)
			for(int b = 0; b < M; b++)
				ans[a][b] = check(a, b);

		if(T > 1)
			printf("\n");

		printf("Field #%d:\n", T++);

		for(int a = 0; a < N; a++){
			for(int b = 0; b < M; b++)
				if(ans[a][b] == -1)
					printf("*");
				else
					printf("%d", ans[a][b]);

			printf("\n");
		}
	}
}
