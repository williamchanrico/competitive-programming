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