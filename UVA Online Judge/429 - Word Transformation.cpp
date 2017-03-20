#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int T;
string inp;

bool oneletter(string x, string y){
	bool once=false;
	if(x.size()!=y.size()) return false;
	for(int a=0, sz=x.size();a<sz;a++)
		if(x[a]!=y[a]) if(once) return false; else once=true;
	return true;
}

int main(){
	cin >> T; cin.ignore();
	getline(cin, inp);
	while(T--){
		vector<int> adjlist[210];
		vector<string> words;
		map<string, int> wordsidx;
		int idx=0;
		do{
			getline(cin, inp);
			words.push_back(inp);
			wordsidx[inp]=idx;
			for(int a=0;a<idx && inp[0]!='*';a++)
				if(oneletter(words[a], inp)){
					adjlist[a].push_back(idx);
					adjlist[idx].push_back(a);
				}
			idx++;
		}while(inp[0]!='*');
		int start;
		string outputstart, outputfinish;
		queue<int> q;
		while(getline(cin, inp)){
			if(inp==""){ if(T!=0) cout << "\n"; break; }
			outputstart=inp.substr(0, inp.find(" "));
			start=wordsidx[outputstart];
			q.push(start);
			outputfinish=inp.substr(inp.find(" ")+1, inp.size()-outputstart.size()-1);
			vector<int> D(words.size(), INF); D[start]=0;
			int finish=wordsidx[outputfinish];
			while(!q.empty()){
				int u=q.front(); q.pop();
				for(int a=0, sz=adjlist[u].size();a<sz;a++){
					int target=adjlist[u][a];
					if(D[target]==INF){
						D[target]=D[u]+1;
						q.push(target);
					}
				}
			}
			cout << outputstart << " " << outputfinish << " ";
			if(D[finish]!=INF) cout << D[finish] << "\n";
			else cout << "-1\n";
			q=queue<int>();
		}
	}
}