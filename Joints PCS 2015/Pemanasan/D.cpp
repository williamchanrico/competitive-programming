#include <bits/stdc++.h>
using namespace std;

int N, M;
int t[1100][1100];

struct TT{
	int left[1100][1100], up[1100][1100], right[1100][1100], down[1100][1100];
} T;

void f(int x, int y, int state){
	//cout << "f(" << x << ", " << y << ", " << state << ")\n";
	switch(state){
	case 1:
		if(T.left[x][y] == 0){
			printf("%d %d\n", x, 0);
			break;
		}

		if(t[x][T.left[x][y]] == 2)
			f(x, T.left[x][y], 4);
		else if(t[x][T.left[x][y]] == 3)
			f(x, T.left[x][y], 2);

		break;
	case 2:
		if(T.up[x][y] == 0){
			printf("%d %d\n", 0, y);
			break;
		}

		if(t[T.up[x][y]][y] == 2)
			f(T.up[x][y], y, 3);
		else if(t[T.up[x][y]][y] == 3)
			f(T.up[x][y], y, 1);

		break;
	case 3:
		if(T.right[x][y] == M + 1){
			printf("%d %d\n", x, M + 1);
			break;
		}

		if(t[x][T.right[x][y]] == 2)
			f(x, T.right[x][y], 2);
		else if(t[x][T.right[x][y]] == 3)
			f(x, T.right[x][y], 4);

		break;
	case 4:
		if(T.down[x][y] == N + 1){
			printf("%d %d\n", N + 1, y);
			break;
		}

		if(t[T.down[x][y]][y] == 2)
			f(T.down[x][y], y, 1);
		else if(t[T.down[x][y]][y] == 3)
			f(T.down[x][y], y, 3);

		break;
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int K, r, c;

	scanf("%d %d %d", &N, &M, &K);

	for(int a = 0; a <= N + 1; a++)
		for(int b = 0; b <= M + 1; b++)
			t[a][b] = 1;

	char z;

	for(int a = 0; a < K; a++){
		scanf("%d %d %c", &r, &c, &z);
		if(z == '/')
			t[r][c] = 2;
		else
			t[r][c] = 3;
	}

	int x;

	for(int a = 0; a <= N + 1; a++){
		x = 0;

		for(int b = 0; b <= M + 1; b++){
			T.left[a][b] = x;

			if(t[a][b] != 1)
				x = b;
		}
	}

	for(int a = 0; a <= N + 1; a++){
		x = M + 1;

		for(int b = M + 1; b >= 0; b--){
			T.right[a][b] = x;

			if(t[a][b] != 1)
				x = b;
		}
	}

	for(int a = 0; a <= M + 1; a++){
		x = 0;

		for(int b = 0; b <= N + 1; b++){
			T.up[b][a] = x;

			if(t[b][a] != 1)
				x = b;
		}
	}

	for(int a = 0; a <= M + 1; a++){
		x = N + 1;

		for(int b = N + 1; b >= 0; b--){
			T.down[b][a] = x;

			if(t[b][a] != 1)
				x = b;
		}
	}

	scanf("%d", &K);

	for(int a = 0; a < K; a++){
		scanf("%d %d", &r, &c);

		if(r == 0)
			f(r, c, 4);
		else if(r == N + 1)
			f(r, c, 2);
		else if(c == 0)
			f(r, c, 3);
		else if(c == M + 1)
			f(r, c, 1);
	}
}
