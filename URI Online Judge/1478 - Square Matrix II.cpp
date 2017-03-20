#include <bits/stdc++.h>
using namespace std;

int tab[105][105];

int main(){
	for(int a=0;a<100;a++)
		tab[a][0]=a+1, tab[0][a]=a+1;
	for(int a=1;a<100;a++)
		for(int b=1;b<100;b++)
			tab[a][b]=tab[a-1][b-1];
	int inp;
	while(scanf("%d", &inp), inp){
		for(int a=0;a<inp;a++){
			for(int b=0;b<inp;b++)
				if(b==0) printf("%3d", tab[a][b]);
				else printf(" %3d", tab[a][b]);
			printf("\n");
		}
		printf("\n");
	}
}