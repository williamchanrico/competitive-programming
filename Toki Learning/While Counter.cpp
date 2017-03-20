#include <stdio.h>

int ans=0, inp;

int main(){
	while(scanf("%d", &inp)!=EOF)
		ans+=inp;
	printf("%d\n", ans);
}
