#include <bits/stdc++.h>
using namespace std;

int f(int x, int y, int z){
	return (x == 0 ? x : x + f((x + z) / y, y, (x + z) % y));
}

int main(){
	int A, B;

	scanf("%d %d", &A, &B);

	printf("%d\n", f(A, B, 0));
}