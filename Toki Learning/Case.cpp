#include <stdio.h>

int n, ans=0;

int main(){
	scanf("%d", &n);
	while(n>0){ n/=10; ans++; }
	switch(ans){
		case 1 : printf("satuan\n"); break;
		case 2 : printf("puluhan\n"); break;
		case 3 : printf("ratusan\n"); break;
		case 4 : printf("ribuan\n"); break;
		case 5 : printf("puluhribuan\n"); break;
	}
}
