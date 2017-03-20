#include <stdio.h>

int M, N;
int B, K, ans=0, maks=-1;
int graph[50][50];

void hitung(int x, int y, int z){
	if(x<M && x>-1 && y<N && y>-1 && graph[x][y]==z){
		graph[x][y]=-1;
		ans++;
		hitung(x-1, y, z);
		hitung(x+1, y, z);
		hitung(x, y-1, z);
		hitung(x, y+1, z);
	}
}

int main(){
	scanf("%d%d", &M, &N);
	for(int a=0;a<M;a++)
		for(int b=0;b<N;b++)
			scanf("%d", &graph[a][b]);
	for(int a=0;a<M;a++)
		for(int b=0;b<N;b++){
			if(graph[a][b]>0 && graph[a][b]<6){
				hitung(a, b, graph[a][b]);
				if(maks<ans)
					maks=ans;
				ans=0;
			}
		}
	printf("%d\n", maks*(maks-1));
}
