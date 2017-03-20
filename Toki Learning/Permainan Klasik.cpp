#include <stdio.h>

long long T, n;

int main(){
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &n);
		if(n%6==0) printf("TIDAK\n");
		else printf("YA\n");
	}
}