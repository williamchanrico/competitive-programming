#include <stdio.h>

int pec[10]={1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
	int inp, n=0;
	scanf("%d", &inp);
	for(int a=0;a<10 && inp!=0;a++){
		while(inp>=pec[a]){
			n++;
			inp-=pec[a];
		}
		if(n!=0)
			printf("%d %d\n", pec[a], n);
		n=0;
	}
}