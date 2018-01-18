#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main(){
	int N, M, arr[60][60];

	scanf("%d %d", &N, &M);

	for(int a = 0; a < N; a++)
		for(int b = 0; b < M; b++)
			scanf("%d", &arr[a][b]);

	int Q, maxi = -INF, mini = INF, sum = 0;

	scanf("%d", &Q);

	while(Q--){
		char cmd[10];
		int idx, val;

		scanf("%s %d %d", cmd, &idx, &val);

		if(cmd[0] == 'r'){

			for(int a = 0; a < M; a++)
				arr[idx - 1][a] += val;
			
		}else{

			for(int a = 0; a < N; a++)
				arr[a][idx - 1] += val;

		}
	}

	for(int a = 0; a < N; a++){
		for(int b = 0; b < M; b++){
			sum += arr[a][b];

			maxi = max(maxi, arr[a][b]);
			mini = min(mini, arr[a][b]);
		}
	}

	printf("%d %d %d\n", sum, mini, maxi);
}