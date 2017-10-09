#include <bits/stdc++.h>
using namespace std;

int main(){
	long long A, B;

	scanf("%I64d %I64d", &A, &B);

	if(B - A >= 10){
		printf("0\n");

		return 0;
	}

	int ans = 1;

	for(long long a = A + 1; a <= B; a++){
		ans = (ans * (1LL * (a % 10))) % 10; 
	}

	printf("%d\n", ans);
}