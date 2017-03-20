#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	bool first=true;
	scanf("%d", &T);
	while(T--){
		int N, M;
		scanf("%d %d", &N, &M);
		while(M--){
			if(!first) printf("\n");
			first=false;
			int num=1;
			for(int a=1;a<N;a++){
				for(int b=0;b<a;b++) printf("%d", num);
				num++;
				printf("\n");
			}
			for(int a=0;a<N;a++) printf("%d", num);
			num--;
			printf("\n");
			for(int a=N-1;a>0;a--){
				for(int b=0;b<a;b++) printf("%d", num);
				num--;
				printf("\n");
			}
		}
	}
}