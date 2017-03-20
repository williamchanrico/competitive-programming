#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> pq;
long long N, B, tmp;

int main(){
	cin >> N >> B;
	for(long long a=0;a<N;a++){
		cin >> tmp;
		pq.push(tmp);
	}
	long long ans=0;
	while(B>0){
		ans++;
		B-=pq.top(); pq.pop();
	}
	cout << ans << "\n";
}