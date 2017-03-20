#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	int B;
	int H;
	int W;
	int price;
	int w;

	vector<int> v;

	while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4){

		v.clear();

		for(int a = 0; a < H; a++){

			scanf("%d", &price);

			for(int b = 0; b < W; b++){

				scanf("%d", &w);

				if(N <= w){

					if(B >= (N*price))
						v.push_back(N * price);

				}

			}

		}
		if(v.empty()){

			printf("stay home\n");

		}else{

			sort(v.begin(), v.end());
			printf("%d\n", v[0]);

		}
	}
}