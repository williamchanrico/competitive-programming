#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main(){
	ios_base::sync_with_stdio(false);
	long long n, inp, mins=INF, maks=-INF;
	map<long long, long long> m;
	cin >> n;
	for(int a=0;a<n;a++){
		cin >> inp;
		if(m.count(inp)==0) m[inp]=1;
		else m[inp]++;
		mins=min(mins, inp);
		maks=max(maks, inp);
	}
	if(mins==maks) cout << maks-mins << " " << n*(n-1)/2 << "\n";
	else cout << maks-mins << " " << m[maks]*m[mins] << "\n";
	
}