#include <bits/stdc++.h>
using namespace std;

int N, memo[100][100];
string inp;

int len(int x, int y){
	if(x==y) return 1;
	if(x+1==y) return (inp[x]==inp[y])?2:1;
	if(memo[x][y]!=-1) return memo[x][y];
	if(inp[x]==inp[y]) return memo[x][y]=2+len(x+1, y-1);
	return memo[x][y]=max(len(x+1, y), len(x, y-1));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	while(N--){
		memset(memo, -1, sizeof(memo));
		cin >> inp;
		cout << len(0, inp.size()-1) << "\n";
	}
}