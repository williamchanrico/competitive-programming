#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	int numSet;
	vector<int> p, rank, setSize;

public:
	UnionFind(int x){
		numSet = x;
		p.assign(x + 1, 0);
		rank.assign(x + 1, 0);
		setSize.assign(x + 1, 1);

		for(int a = 0; a <= x; a++)
			p[a] = a;
	}

	int findSet(int x){ return (p[x] == x ? x : findSet(p[x])); }

	bool isSameSet(int x, int y){ return (findSet(p[x]) == findSet(p[y])); }

	void unionSet(int x, int y){
		if(!isSameSet(x, y)){
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

			numSet--;
		}
	}

	int sizeOfSet(int x){ return setSize[findSet(x)]; }
};

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int F, idx = 0;
		UnionFind UF(100000);
		map<string, int> m;

		scanf("%d", &F);

		while(F--){
			string p1, p2;

			cin >> p1 >> p2;

			if(!m.count(p1)) m[p1] = idx++;
			if(!m.count(p2)) m[p2] = idx++;

			if(!UF.isSameSet(m[p1], m[p2]))
				UF.unionSet(m[p1], m[p2]);

			printf("%d\n", UF.sizeOfSet(m[p1]));
		}
	}
}
