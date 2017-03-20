#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n=0;
		double N, M, P, Q;
		cin >> N >> M >> P >> Q;
		//cout << N << " " << M << "\n";
		while(N<=M){
			N+=floor(N*(P/100));
			M+=floor(M*(Q/100));
			n++;
			//cout << N << " " << M << " " << n << "\n";
			if(n==100 && N<=M){
				cout << "Mais de 1 seculo.\n";
				break;
			}else{
				if(N>M) cout << n << " anos.\n";
			}
		}
	}
}
