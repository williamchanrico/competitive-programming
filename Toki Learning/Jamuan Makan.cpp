#include<bits/stdc++.h>
using namespace std;

int n, start, end, ans=0;
vector< pair<int, int> > v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int a=0;a<n;a++){
		cin >> start >> end;
		v.push_back(make_pair(end+start-1, start));
	}
	sort(v.begin(), v.end());
	int u=0;
	for(int a=0, sz=v.size();a<sz;a++){
		while(v[a].first<u && a<sz){ a++; }
		if(v[a].second>u && a<sz){
			u=v[a].first;
			ans++;
		}
	}
	cout << ans << "\n";
}