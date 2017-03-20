#include <bits/stdc++.h>
using namespace std;

int T, n, inp;
bitset<10001> explore1, explore2;
char dom[110][110];
vector<int> adjlist[110];

void dfs(int x, int y){
	if(x!=y){
		explore2[x]=false;
		for(int a=0, sz=adjlist[x].size();a<sz;a++)
			if(explore2[adjlist[x][a]])
				dfs(adjlist[x][a], y);
	}
}

void firstdfs(int x){
	explore1[x]=false;
	for(int a=0, sz=adjlist[x].size();a<sz;a++)
		if(explore1[adjlist[x][a]])
			firstdfs(adjlist[x][a]);
}

int main(){
	cin >> T;
	for(int CASE=1;CASE<=T;CASE++){
		cin >> n;
		for(int a=0;a<n;a++)
			for(int b=0;b<n;b++){
				cin >> inp;
				if(inp) adjlist[a].push_back(b);
			}
		explore1.set(); explore2.set();
		firstdfs(0);
		for(int a=0;a<n;a++){
			dfs(0, a);
			for(int b=0;b<n;b++){
				if(explore2[b] && !explore1[b]) dom[a][b]='Y';
				else dom[a][b]='N';
			}
			explore2.set();
		}
		cout << "Case " << CASE << ":\n";
		for(int a=0;a<n;a++){
			for(int b=0;b<2*n+1;b++)
				if(b==0 || b==(2*n)) cout << "+";
				else cout << "-";
			cout << "\n|";
			for(int b=0;b<n;b++)
				cout << dom[a][b] << "|";
			cout << "\n";
		}
		for(int b=0;b<2*n+1;b++)
				if(b==0 || b==(2*n)) cout << "+";
				else cout << "-";
		cout << "\n";
		for(int a=0;a<110;a++) adjlist[a].clear();
	}
}