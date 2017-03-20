#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int T, n, m;
vector< pair<int, int> > AdjList[1010];

int main(){
	scanf("%d", &T);
	while(T--){
		int x, y, t;
		scanf("%d %d", &n, &m);
		for(int a=0;a<m;a++){
			scanf("%d %d %d", &x, &y, &t);
			AdjList[x].push_back(make_pair(y, t));
		}
		vector<int> dist(n, INF); dist[0]=0;
		for(int a=0;a<n-1;a++){
			for(int b=0;b<n;b++){
				for(int c=0;c<AdjList[b].size();c++){
					pair<int, int> target=AdjList[b][c];
					dist[target.first]=min(dist[target.first], dist[b]+target.second);
				}
			}
		}
		bool possible=false;
		for(int a=0;a<n;a++){
			for(int b=0;b<AdjList[a].size();b++){
				pair<int, int> target=AdjList[a][b];
				if(dist[target.first]>dist[a]+target.second){
					possible=true;
					break;
				}
			}
		}
		if(possible) printf("possible\n");
		else printf("not possible\n");
		for(int a=0;a<n;a++)
			AdjList[a].clear();
	}
}