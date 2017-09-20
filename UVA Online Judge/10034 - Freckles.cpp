#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	vector<int> rank, p, setSize;
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
		}
	}

	int numOfSet(int x){ return numSet; }

	int sizeOfSet(int x){ return setSize[findSet(x)]; }

};

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int N;
		double X[110], Y[110];
		vector<pair<double, pair<int, int> > > edgeList;

		scanf("%d", &N);

		for(int a = 0; a < N; a++){
			scanf("%lf %lf", &X[a], &Y[a]);

			for(int b = 0; b < a; b++){
				double dist = hypot(X[b] - X[a], Y[b] - Y[a]);

				edgeList.push_back(make_pair(dist, make_pair(a, b)));
			}
		}

		sort(edgeList.begin(), edgeList.end());

		double mst = 0;
		UnionFind UF(N);

		for(int a = 0; a < edgeList.size(); a++){
			if(!UF.isSameSet(edgeList[a].second.first, edgeList[a].second.second)){
				mst += edgeList[a].first;

				UF.unionSet(edgeList[a].second.first, edgeList[a].second.second);
			}
		}

		printf("%.2lf\n", mst);

		if(T) printf("\n");
	}
}
