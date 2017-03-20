#include <stdio.h>

int main(){
	long long n, ans;
	scanf("%lld", &n);
	ans=(n*(n+1)*((2*n)+1));
	printf("%lld\n", ans/6);
}