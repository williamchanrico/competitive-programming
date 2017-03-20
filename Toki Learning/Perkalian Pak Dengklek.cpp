#include <stdio.h>

long long ans=0, A, B, arrA[15], arrB[15];

int main(){
	scanf("%lld %lld", &A, &B);
	for(int a=0;A>0;a++, A/=10) arrA[a]=A%10, arrA[a+1]=-1;
	for(int a=0;B>0;a++, B/=10) arrB[a]=B%10, arrB[a+1]=-1;
	for(int a=0;arrA[a]!=-1;a++)
		for(int b=0;arrB[b]!=-1;b++)
			ans+=arrA[a]*arrB[b];
	printf("%lld\n", ans);
}
