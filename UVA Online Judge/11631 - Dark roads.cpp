#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	vector<int> p;
	vector<int> rank;
	vector<int> setSize;
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

	int findSet(int x){
		return (p[x] == x ? x : findSet(p[x]));
	}

	bool isSameSet(int x, int y){
		return (findSet(p[x]) == findSet(p[y]));
	}

	void unionSet(int x, int y){
		int a = findSet(x);
		int b = findSet(y);

		--numSet;

		if(rank[a] < rank[b]){
			p[a] = b;
			setSize[b] += setSize[a];
		}else{
			p[b] = a;
			setSize[a] += setSize[b];
			if(rank[a] == rank[b]) ++rank[a];
		}
	}

	int numOfSet(){
		return numSet;
	}

	int sizeOfSet(int x){
		return setSize[findSet(x)];
	}
};

vector<pair<int, pair<int, int> > > EdgeList;
int m, n;

int main(){
	// freopen("in.txt", "r", stdin);

	while(scanf("%d %d", &m, &n) && (m || n)){
		int x;
		int y;
		int z;
		int totalLen = 0;

		for(int a = 0; a < n; a++){
			scanf("%d %d %d", &x, &y, &z);
			totalLen += z;
			EdgeList.push_back(make_pair(z, make_pair(x, y)));
		}


		sort(EdgeList.begin(), EdgeList.end());

		int mstCost = 0;

		UnionFind UF(m);

		for(int a = 0; a < n; a++){
			if(!UF.isSameSet(EdgeList[a].second.first, EdgeList[a].second.second)){
				UF.unionSet(EdgeList[a].second.first, EdgeList[a].second.second);
				mstCost += EdgeList[a].first;
			}
		}

		printf("%d\n", totalLen - mstCost);
		EdgeList.clear();
	}
}