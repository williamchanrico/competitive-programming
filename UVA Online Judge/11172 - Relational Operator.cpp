#include <stdio.h>

long long inp1, inp2;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &inp1, &inp2);
		if(inp1>inp2)
			printf(">\n");
		else if(inp1<inp2)
			printf("<\n");
		else
			printf("=\n");
	}
}