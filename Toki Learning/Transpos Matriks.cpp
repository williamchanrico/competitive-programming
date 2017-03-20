#include <stdio.h>

int data[5][5];

int main(){
	for(int a=0;a<3;a++)
		for(int b=0;b<3;b++)
			scanf("%d", &data[a][b]);
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++)
			if(b==0) printf("%d", data[b][a]); else printf(" %d", data[b][a]);
		printf("\n");
	}
}
