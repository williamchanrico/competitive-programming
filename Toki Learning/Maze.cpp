#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int N, M, nN, nM;
int grid[105][105];
int da[]={-1, 0, 1, 0};
int db[]={0, 1, 0, -1};

int main(){
	queue< pair<int, int> > q;
	scanf("%d %d", &N, &M); getchar();
	for(int a=0;a<N;a++)
		for(int b=0;b<M;b++)
			scanf("%d", &grid[a][b]);
	scanf("%d %d", &nN, &nM); getchar();
	q.push(make_pair(nN-1, nM-1));
	grid[nN-1][nM-1]=1;
	while(!q.empty()){
		pair<int, int> p = q.front(); q.pop();
		if(p.first==0 || p.second==0 || p.first==N-1 || p.second==M-1){
			printf("1\n");
			return 0;
		}
		for(int a=0;a<4;a++){
			int na=p.first+da[a], nb=p.second+db[a];
			if(na>-1 && nb>-1 && na<N && nb<M && grid[na][nb]==0){
				q.push(make_pair(na, nb));
				grid[na][nb]=grid[na-da[a]][nb-db[a]]+1;	
				if(na==0 || na==N-1 || nb==0 || nb==M-1){
					printf("%d\n", grid[na][nb]);
					return 0;
				}
			}
		}
	}
	/*
	puts("\n----debug----");
	for(int a=0;a<N;a++){
		for(int b=0;b<M;b++)
			if(grid[a][b]==-1)
				printf("#  ");
			else
				if(grid[a][b]>9)
					printf("%d ", grid[a][b]);
				else
					printf("%d  ", grid[a][b]);
		printf("\n");
	} 
	
	 
	
8 10
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 0 0 0 0 0 -1 0 0 0
-1 0 0 -1 -1 0 0 0 -1 -1
-1 -1 0 0 -1 -1 -1 0 0 -1
-1 0 0 0 -1 0 -1 -1 0 -1
-1 0 -1 0 -1 0 -1 0 0 -1
-1 0 -1 0 0 0 0 0 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
7 5
	
	*/	
}