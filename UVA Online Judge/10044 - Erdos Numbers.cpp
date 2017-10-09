#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main(){
	int T;

	cin >> T;

	for(int TC = 1; TC <= T; TC++){
		string inp;
		map<string, int> m;
		vector<vector<int> > adjList(10000);
		int P, N, count = 0;

		cin >> P >> N;
		
		cin.ignore(INT_MAX, '\n');

		m["Erdos, P."] = count++;

		while(P--){
			vector<string> v;
			int sPos = 0, ePos = 0;

			getline(cin, inp);
			
			while( (ePos = inp.find(".,", sPos)) != string::npos){
				v.push_back(inp.substr(sPos, ePos - sPos + 1));

				sPos = ePos + 3;
			}

			ePos = inp.find(".:");

			v.push_back(inp.substr(sPos, ePos - sPos + 1));

			for(int a = 0; a < v.size(); a++)
				if(!m.count(v[a]))
					m[v[a]] = count++;
			
			for(int a = 0; a < v.size(); a++){
				for(int b = 0; b < a; b++){
					adjList[m[v[a]]].push_back(m[v[b]]);
					adjList[m[v[b]]].push_back(m[v[a]]);
				}
			}
		}

		cout << "Scenario " << TC << "\n";

		while(N--){
			getline(cin, inp);

			int ans = -1;
			queue<int> q;
			vector<int> dist(count, INF);

			q.push(m[inp]);

			dist[m[inp]] = 0;

			while(!q.empty()){
				int u = q.front();

				q.pop();

				for(int a = 0; a < adjList[u].size(); a++){
					int v = adjList[u][a];

					if(dist[v] == INF){
						dist[v] = dist[u] + 1;

						if(v == 0){
							ans = dist[v];

							break;
						}

						q.push(v);
					}
				}

				if(ans != -1) break;
			}

			if(ans == -1)
				cout << inp << " infinity\n";
			else
				cout << inp << " " << ans << "\n";
		}
	}
}
