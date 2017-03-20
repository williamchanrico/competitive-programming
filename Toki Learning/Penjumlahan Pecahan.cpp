#include <stdio.h>
 
long long A, B, C, D, penyebut, pembilang;
 
long long fpb(long long x, long long y){ return (y==0)?x:fpb(y, x%y); }
long long kpk(long long x, long long y){ return x*(y/fpb(x, y)); }
 
int main(){
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    penyebut=kpk(B, D);
	pembilang=((penyebut/B)*A)+((penyebut/D)*C);
    printf("%lld %lld\n", pembilang/fpb(pembilang, penyebut), penyebut/fpb(pembilang, penyebut));
}