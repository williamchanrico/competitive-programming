#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

bool valid(const string &x, const string &y){
	bool ret = false;

	if(x.size() != y.size())
		return false;

	for(int a = 0; a < x.size(); a++)
		if(x[a] != y[a])
			if(!ret)
				ret = true;
			else
				return false;

	return true;
}

int main(){
	int T;

	cin >> T;

	while(T--){
		string str;
		map<string, int> m;
		vector<string> dict;
		vector<vector<int> > adjList(210);

		while(cin >> str, str[0] != '*'){
			dict.push_back(str);

			m[str] = dict.size() - 1;
			
			for(int a = 0; a < (dict.size() - 1); a++){
				if(valid(str, dict[a])){
					adjList[a].push_back(m[str]);
					adjList[m[str]].push_back(a);
				}
			}
		}

		cin.ignore(INT_MAX, '\n');

		while(getline(cin, str), str != ""){
			string w1, w2;
			stringstream ss(str);

			ss >> w1 >> w2;

			int start = m[w1], end = m[w2];

			queue<int> q;
			vector<int> dist(dict.size(), INF);

			dist[start] = 0;

			q.push(start);

			while(!q.empty()){
				int u = q.front();

				q.pop();

				for(int a = 0; a < adjList[u].size(); a++){
					if(dist[adjList[u][a]] == INF){
						q.push(adjList[u][a]);

						dist[adjList[u][a]] = dist[u] + 1;

						if(adjList[u][a] == end){
							queue<int>().swap(q);

							break;
						}
					}
				}
			}

			cout << w1 << " " << w2 << " " << dist[end] << "\n";
		}

		if(T) cout << "\n";
	}
}
