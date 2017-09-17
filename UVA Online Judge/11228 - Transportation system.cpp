#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	vector<int> p, rank, setSize;
	int numSet;

public:
	UnionFind(int x){
		p.assign(x, 0);
		rank.assign(x, 0);
		setSize.assign(x, 1);

		numSet = x;

		for(int a = 0; a < x; a++)
			p[a] = a;
	}

	int findSet(int x){ return (p[x] == x ? x : findSet(p[x])); }

	bool isSameSet(int x, int y){ return (findSet(x) == findSet(y)); }

	void unionSet(int x, int y){
		int a = findSet(x);
		int b = findSet(y);

		if(!isSameSet(a, b)){
			numSet--;

			if(rank[a] > rank[b]){
				p[b] = a;
				setSize[a] += setSize[b];
			}else{
				p[a] = b;
				setSize[b] += setSize[a];

				if(rank[a] == rank[b]) rank[b]++;
			}
		}
	}

	int sizeOfSet(int x){ return setSize[findSet(x)]; }

	int numOfSet(){ return numSet; }
};

int main(){
	int T;

	scanf("%d", &T);

	for(int TC = 1; TC <= T; TC++){
		int N, R, X, Y, dist[1100][1100];
		vector<pair<int, int> > city;
		vector<pair<int, pair<int, int> > > edgeList;

		scanf("%d %d", &N, &R);

		for(int a = 0; a < N; a++){
			scanf("%d %d", &X, &Y);

			city.push_back(make_pair(X, Y));
		}

		for(int a = 0; a < N; a++){
			for(int b = a + 1; b < N; b++){
				X = (city[b].first - city[a].first);
				Y = (city[b].second - city[a].second);

				dist[a][b] = dist[b][a] = (X * X) + (Y * Y);
			}
		}


		for(int a = 0; a < N; a++)
			for(int b = a + 1; b < N; b++)
				edgeList.push_back(make_pair(dist[a][b], make_pair(a, b)));

		sort(edgeList.begin(), edgeList.end());

		UnionFind UF(N);
		int states = 1;
		double roads = 0, rails = 0;

		for(int a = 0; a < edgeList.size(); a++){
			pair<int, int> u = edgeList[a].second;

			if(!UF.isSameSet(u.first, u.second)){
				UF.unionSet(u.first, u.second);

				if(edgeList[a].first < (R * R)){
					roads += sqrt((double) edgeList[a].first);
				}else{
					states++;
					rails += sqrt((double) edgeList[a].first);
				}
			}
		}

		printf("Case #%d: %d %.0lf %.0lf\n", TC, states, round(roads), round(rails));
	}
}
