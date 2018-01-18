#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class UnionFind{
private:
	int numSet;
	vector<int> rank, p, setSize;

public:
	UnionFind(){}

	UnionFind(int x){
		p.assign(x, 0);
		rank.assign(x, 0);
		setSize.assign(x, 1);

		numSet = x;

		for(int a = 0; a < x; a++)
			p[a] = a;
	}

	int findSet(int x){ return (x == p[x] ? x : findSet(p[x])); }

	bool isSameSet(int x, int y){ return (findSet(x) == findSet(y)); }

	void unionSet(int x, int y){
		if(!isSameSet(x, y)){
			int A = findSet(x);
			int B = findSet(y);

			if(rank[A] < rank[B]){
				p[A] = B;
				setSize[B] += setSize[A];
			}else{
				p[B] = A;
				setSize[A] += setSize[B];

				if(rank[A] == rank[B])
					rank[A]++;
			}

			--numSet;
		}
	}

	int sizeOfSet(int x){ return setSize[findSet(x)]; }

	int numOfSet(){ return numSet; }
};

int N, M;
vector<pair<int, pair<int, int> > > edgeList;

pair<int, vector<int> > mst(int flag = -1){
	int mst = 0;
	UnionFind UF(N);
	vector<int> usedEdge;

	for(int a = 0; a < edgeList.size(); a++){
		int W = edgeList[a].first;
		pair<int, int> V = edgeList[a].second;

		if(a == flag || a == flag)
			continue;

		if(!UF.isSameSet(V.first, V.second)){
			UF.unionSet(V.first, V.second);
			usedEdge.push_back(a);
			mst += W;
		}
	}
	
	if(UF.numOfSet() != 1)
		mst = INF;

	return make_pair(mst, usedEdge);
}

bool cmp(const pair<int, pair<int, int> > &x, const pair<int, pair<int, int> > &y){
	return x.first > y.first;
}

int main(){
	int TC;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &N, &M);
		
		edgeList.clear();

		int sum = 0;

		for(int a = 0; a < M; a++){
			int A, B, C;

			scanf("%d %d %d", &A, &B, &C);

			edgeList.push_back(make_pair(C, make_pair(A - 1, B - 1)));

			sum += C;
		}

		sort(edgeList.begin(), edgeList.end(), cmp);

		pair<int, vector<int> > ans = mst();

		printf("%d\n", sum - ans.first);
	}

	scanf("0");
}
