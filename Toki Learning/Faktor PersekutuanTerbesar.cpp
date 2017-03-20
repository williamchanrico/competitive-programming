#include <stdio.h>

int T;
long long A, B;

long long fpb(long long x, long long y){ return (y==0)?x:fpb(y, x%y); }
long long kpk(long long x, long long y){ return x*(y/fpb(x, y)); }

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &A, &B);
		printf("%lld\n", fpb(A, B));
	}
}