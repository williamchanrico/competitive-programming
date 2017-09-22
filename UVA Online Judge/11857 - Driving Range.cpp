#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

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
		if(!isSameSet(x, y)){
			int a = findSet(x);
			int b = findSet(y);

			if(rank[a] < rank[b]){
				p[a] = b;
				setSize[b] += setSize[a];
			}else{
				p[b] = a;
				setSize[a] += setSize[b];

				if(rank[a] == rank[b]) rank[a]++;
			}

			numSet--;
		}
	}

	int numOfSet(){ return numSet; }

	int sizeOfSet(int x){ return setSize[findSet(x)]; }
};

int main(){
	int N, M;

	while(scanf("%d %d", &N, &M), (N | M)){
		int A, B, cost;
		vector<pair<int, pair<int, int> > > edgeList;

		for(int a = 0; a < M; a++){
			scanf("%d %d %d", &A, &B, &cost);

			edgeList.push_back(make_pair(cost, make_pair(A, B)));
		}

		sort(edgeList.begin(), edgeList.end());

		int ans = -INF;
		UnionFind UF(N);

		for(int a = 0; a < edgeList.size(); a++){
			if(!UF.isSameSet(edgeList[a].second.first, edgeList[a].second.second)){
				UF.unionSet(edgeList[a].second.first, edgeList[a].second.second);

				ans = max(ans, edgeList[a].first);
			}
		}

		if(UF.numOfSet() != 1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
}
