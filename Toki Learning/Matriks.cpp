#include <stdio.h>

int matriks[105][105];
int N, M;

int main(){
	scanf("%d %d", &N, &M);
	for(int a=0;a<N;a++)
		for(int b=0;b<M;b++)
			scanf("%d", &matriks[a][b]);
	for(int a=0;a<M;a++){
		for(int b=N-1;b>-1;b--)
			if(b==N-1) printf("%d", matriks[b][a]);
			else printf(" %d", matriks[b][a]);
		printf("\n");
	}
}
