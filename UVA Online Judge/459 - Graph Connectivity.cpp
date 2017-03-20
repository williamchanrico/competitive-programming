#include <bits/stdc++.h>
using namespace std;

int T;
string inp;
map<char, int> m;
vector<int> adjlist[30];
bitset<30> explore;

void dfs(int x){
	explore[x]=false;
	for(int a=0, sz=adjlist[x].size();a<sz;a++)
		if(explore[adjlist[x][a]])
			dfs(adjlist[x][a]);
}

void bfs(int x){

	queue<int> q;
	q.push(x);

	while(!q.empty()){

		int u = q.front();
		q.pop();
		explore[u] = false;
		
		for(int a=0;a<adjlist[u].size();a++)
			if(explore[adjlist[u][a]])
				q.push(adjlist[u][a]);

	}

}

int main(){
	int idx=1;
	for(char a='A';a<='Z';a++) m[a]=idx++;
	cin >> T; cin.ignore();
	getline(cin, inp);
	while(T--){
		int end;
		getline(cin, inp);
		end=m[inp[0]];
		do{
			getline(cin, inp);
			adjlist[m[inp[0]]].push_back(m[inp[1]]);
			adjlist[m[inp[1]]].push_back(m[inp[0]]);
		}while(inp!="");
		int ans=0;
		explore.set();
		for(int a=1;a<=end;a++)
			if(explore[a])
				ans++, dfs(a);
		cout << ans << "\n";
		if(T!=0) cout << "\n";
		for(int a=0;a<30;a++) adjlist[a].clear();
	}
}