#include <stdio.h>

int n;

int main(){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		for(int b=n-a;b>0;b--) printf(" ");
		for(int b=1;b<=a;b++) printf("*");
		printf("\n");
	}
}
