#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	int M;
	int K;
	int ans;

	cin >> N >> M >> K;

	ans = (N / M) + (N % M ? 1 : 0);
	
	cout << ans + (ans == K ? 0 : ans / K) - (ans % K == 0 && (ans != K ? 1 : 0)) << "\n";
}