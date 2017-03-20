#include <stdio.h>

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	for(int a=1;a<=n;a++){
		if(a==1) if(a%k==0) printf("*"); else printf("%d", a);
		else if(a%k==0) printf(" *"); else printf(" %d", a);
	}
	printf("\n");
}
