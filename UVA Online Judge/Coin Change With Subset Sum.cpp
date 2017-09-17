#include <bits/stdc++.h>
using namespace std;

int main(){
	int memo[36];
	int arr[] = {1, 2, 3};
	int N = 4;

	memset(memo, 0, sizeof(memo));
	
	memo[0] = 1;

	for(int a = 0; a < sizeof(arr) / sizeof(arr[0]); a++){
		for(int b = N; b >= arr[a]; b--){ // reverse the loop for unlimited coins
			memo[b] += memo[b - arr[a]];
		}
		// for(int b = 0; b <= N; b++)
		// 	printf("%d ", memo[b]);
		// printf("\n");
	}
}