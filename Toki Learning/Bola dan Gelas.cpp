#include <stdio.h>
#include <algorithm>

int gelas[100005];
int n, m , x1, x2;

int main(){
	scanf("%d %d", &n, &m);
	for(int a=1;a<=n;a++)
		gelas[a]=a;
	for(int a=0;a<m;a++){
		scanf("%d %d", &x1, &x2);
		std::swap(gelas[x1], gelas[x2]);
	}
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		printf("%d\n", gelas[m]);
	}
}
