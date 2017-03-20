#include <bits/stdc++.h>
using namespace std;
 
vector< pair<long long, long long> > batu;
long long V, H, n, peta[510][510], memo[250000];
 
long long jatuh(long long x, long long y){
	if(x==V+1 || y<1 || y>H) return 0;
	if(peta[x][y]!=-1){
		if(memo[peta[x][y]]!=-1) return memo[peta[x][y]];
		return memo[peta[x][y]]=1+jatuh(x-1, batu[peta[x][y]].first)+jatuh(x-1, batu[peta[x][y]].second);
	}
	return jatuh(x+1, y);
}
 
int main(){
	memset(peta, -1, sizeof(peta));
	memset(memo, -1, sizeof(memo));
 
	long long v1, h1, v2, h2;
	cin >> V >> H >> n;
	for(long long a=0;a<n;a++){
		cin >> v1 >> h1 >> v2 >> h2;
		for(long long b=v1;b<=v2;b++)
			for(long long c=h1;c<=h2;c++)
				peta[b][c]=a;
		batu.push_back(make_pair(h1-1, h2+1));
	}
	long long ans=-1;
	for(long long a=1;a<=H;a++)
		ans=max(ans, jatuh(0, a));
	cout << ans << "\n";
}