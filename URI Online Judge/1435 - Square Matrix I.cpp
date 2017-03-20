#include <bits/stdc++.h>
using namespace std;

int tab[105][105];

int main(){
	int inp;
	scanf("%d", &inp);
	while(inp!=0){
		memset(tab, 0, sizeof(tab));
		for(int a=0;a<(inp+1)/2;a++)
			for(int b=a;b<inp-a;b++)
				for(int c=a;c<inp-a;c++)
					tab[b][c]++;
		for(int a=0;a<inp;a++){
			for(int b=0;b<inp;b++)
				if(b==0) printf("%3d", tab[a][b]);
				else printf(" %3d", tab[a][b]);
			printf("\n");
		}
		printf("\n");
		scanf("%d", &inp);
	}
}