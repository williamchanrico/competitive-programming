#include <stdio.h>

int n, ans=0;

int main(){
	scanf("%d", &n);
	for(int a=5;a<=n;a*=5)
		ans+=n/a;
	printf("%d\n", ans);
}

/*
#include <stdio.h>

int n;

int main(){
	scanf("%d", &n);
	if(n>10 || n<0){ puts("ditolak"); }
	else{
		if(n==0) n=1;
		for(int a=1, sz=n;a<sz;a++) n*=a;
		printf("%d\n", n);
	}
}
*/