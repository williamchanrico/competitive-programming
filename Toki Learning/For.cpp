#include <stdio.h>

int n, ans;

int main(){
	scanf("%d", &n);
	for(int a=n;a>0;a--)
		scanf("%d", &n), ans+=n;
	printf("%d\n", ans);
}
