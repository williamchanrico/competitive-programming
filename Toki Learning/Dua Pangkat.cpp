#include <stdio.h>

long long inp;

bool proses(long long x){
	return (x!=0 && !(x&(x-1)));
}

int main(){
	scanf("%lld", &inp);
	printf("%s\n", (proses(inp)?"TRUE":"FALSE"));
}
