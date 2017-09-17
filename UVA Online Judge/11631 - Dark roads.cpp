#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	int numSet;
	vector<int> p, rank, setSize;

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
			numSet--;

			int a = findSet(x);
			int b = findSet(y);

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

	int numOfSet(){ return numSet; }

	int sizeOfSet(int x){ return setSize[findSet(x)]; }
};

int main(){
	int M, N;

	while(scanf("%d %d", &M, &N), M | N){
		int X, Y, Z, sum = 0;
		vector<pair<int, pair<int, int> > > edgeList;

		for(int a = 0; a < N; a++){
			scanf("%d %d %d", &X, &Y, &Z);

			sum += Z;

			edgeList.push_back(make_pair(Z, make_pair(X, Y)));
		}

		sort(edgeList.begin(), edgeList.end());

		int mst = 0;
		UnionFind UF(M);

		for(int a = 0; a < N; a++){
			pair<int, pair<int, int> > u = edgeList[a];

			if(!UF.isSameSet(u.second.first, u.second.second)){
				mst += u.first;

				UF.unionSet(u.second.first, u.second.second);
			}
		}

		printf("%d\n", sum - mst);
	}

}
