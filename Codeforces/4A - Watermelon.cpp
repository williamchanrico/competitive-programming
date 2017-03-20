#include <stdio.h>

int main(){
	int w;
	scanf("%d", &w);
	printf("%s\n", (w>2 && w%2==0)?"YES":"NO");
}