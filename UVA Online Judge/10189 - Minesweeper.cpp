#include <stdio.h>

char graph[500][500];
int rgraph[500][500];

int main(){
	int n, m, counter=0;
	while(scanf("%d%d", &n, &m), (n||m)){
	
		for(int a=0;a<n;a++)
			scanf("%s", graph[a]);
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(graph[a][b]!='*'){
					int x=0;
					if(graph[a-1][b]=='*')x++;
					if(graph[a+1][b]=='*')x++;
					if(graph[a][b-1]=='*')x++;
					if(graph[a][b+1]=='*')x++;
					if(graph[a-1][b-1]=='*')x++;
					if(graph[a-1][b+1]=='*')x++;
					if(graph[a+1][b+1]=='*')x++;
					if(graph[a+1][b-1]=='*')x++;
					rgraph[a][b]=x;
				}else{
					rgraph[a][b]=9;
				}
			}
		}
		if(counter>0)
			printf("\n");
		counter++;
		printf("Field #%d:\n", counter);
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(rgraph[a][b]!=9)
					printf("%d", rgraph[a][b]);
				else
					printf("*");
			}
			printf("\n");
		}
		for(int a=0;a<n;a++)
			for(int b=0;b<m;b++){
				graph[a][b]=0;
				rgraph[a][b]=0;
			}
	}
	
}
