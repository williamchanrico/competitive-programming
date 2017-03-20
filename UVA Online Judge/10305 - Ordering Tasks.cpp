#include <bits/stdc++.h>
using namespace std;

vector<int> AdjList[110], ts;
int n, m;
bitset<110> explore;

void dfs(int x){
	explore[x]=false;
	for(int a=0;a<AdjList[x].size();a++)
		if(explore[AdjList[x][a]])
			dfs(AdjList[x][a]);
	ts.push_back(x);
}

int main(){
	while(scanf("%d%d", &n, &m), (n||m)){
		explore.set();
		int inp1, inp2;
		for(int a=0;a<m;a++){
			cin >> inp1 >> inp2;
			AdjList[inp1].push_back(inp2);
		}
		for(int a=1;a<=n;a++)
			if(explore[a]) dfs(a);
		for(int a=ts.size()-1;a>-1;a--)
			if(a!=0) cout << ts[a] << " ";
			else cout << ts[a] << "\n";
		for(int a=0;a<110;a++) AdjList[a].clear();
		ts.clear();
	}
}