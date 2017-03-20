#include <stdio.h>

int T, n, m;
char graph[100][100];

void dfs(int x, int y){
	if(graph[x][y]==' ' && x<n && y<m && x>=0 && y>=0){
		graph[x][y]='.';
		dfs(x+1, y);
		dfs(x-1, y);
		dfs(x, y+1);
		dfs(x, y-1);
	}
}

void cekgraph(){
	for(int a=0;a<n;a++){
		puts(graph[a]);
	}
}

void cek(){
	for(int a=0;a<n;a++)
		for(int b=0;b<m;b++){
			if(graph[a][b]==' '){
				printf("YA\n");
				//cekgraph();
				return;
			}
		}
	printf("TIDAK\n");
	//cekgraph();
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		getchar();
		for(int a=0;a<n;a++)
			gets(graph[a]);
		int x=0, y=0, yy=m-1;
		while(x<n){
			if(graph[x][y]==' ')
				dfs(x, y);
			if(graph[x][yy]==' ')
				dfs(x, yy);
			x++;
		}
		x=0; y=0; yy=n-1;
		while(y<m){
			if(graph[x][y]==' ')
				dfs(x, y);
			if(graph[yy][y]==' ')
				dfs(yy, y);
			y++;
		}
		cek();	
	}
}


/*

#include <cstdio>
#include <queue>
#include <utility>

#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;

const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

int main()
{
	int T,N,M,cnt;
	char c;
	bool grid[85][85];
	scanf("%d",&T);
	while (T--)
	{
		queue<ii> q;
		scanf("%d %d\n",&N,&M);
		cnt = N*M;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%c",&c);
				grid[i][j] = (c == ' ');
				if (!grid[i][j])
					--cnt;
				else if ((i == 0) || (i == (N-1)) || (j == 0) || (j == (M-1)))
				{
					q.push(ii(i,j));
					grid[i][j] = false;
					--cnt;
				}
			}
			getchar();
		}
		
		while (!q.empty())
		{
			ii u = q.front(); q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int ni = u.fi+di[k], nj = u.se+dj[k];
				if ((ni >= 0) && (ni < N) && (nj >= 0) && (nj < M) && (grid[ni][nj]))
				{
					q.push(ii(ni,nj));
					grid[ni][nj] = false;
					--cnt;
				}
			}
		}
		printf("%s\n",(cnt)?"YA":"TIDAK");
	}
	return 0;
}


*/