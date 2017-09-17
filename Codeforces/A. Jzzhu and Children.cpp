#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int main(){
	int N;
	int M;
	int inp;
	int ans;
	int maxi = -INF;

	scanf("%d %d", &N, &M);

	for(int a = 0; a < N; a++){
		scanf("%d", &inp);

		int temp = (inp / M) + (inp % M ? 1 : 0);

		if(maxi <= temp){
			maxi = temp;
			ans = a + 1;
		}
	}

	printf("%d\n", ans);
}