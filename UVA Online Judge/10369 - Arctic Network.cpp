#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

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

			numSet--;

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

	int numOfSet(){ return numSet; };

	int sizeOfSet(int x){ return setSize[findSet(x)]; }

};

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int S, P, X[510], Y[510];

		scanf("%d %d", &S, &P);

		vector<pair<double, pair<int, int> > > edgeList;

		for(int a = 0; a < P; a++){

			scanf("%d %d", &X[a], &Y[a]);

			for(int b = 0; b < a; b++){
				double cost = hypot(X[a] - X[b], Y[a] - Y[b]);

				edgeList.push_back(make_pair(cost, make_pair(a, b)));
			}

		}

		sort(edgeList.begin(), edgeList.end());

		UnionFind UF(P);
		double ans = 0;

		for(int a = 0; a < edgeList.size(); a++){
			if(!UF.isSameSet(edgeList[a].second.first, edgeList[a].second.second)){
				UF.unionSet(edgeList[a].second.first, edgeList[a].second.second);

				ans = edgeList[a].first;

				if(UF.numOfSet() == S)
					break;
			}
		}

		printf("%.2lf\n", ans);
	}
}

/*
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

			numSet--;

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

	int numOfSet(){ return numSet; };

	int sizeOfSet(int x){ return setSize[findSet(x)]; }

};

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int S, P, X[510], Y[510];

		scanf("%d %d", &S, &P);

		vector<pair<double, pair<int, int> > > edgeList;

		for(int a = 0; a < P; a++){

			scanf("%d %d", &X[a], &Y[a]);

			for(int b = 0; b < a; b++){
				double cost = hypot(X[a] - X[b], Y[a] - Y[b]);

				edgeList.push_back(make_pair(cost, make_pair(a, b)));
			}

		}

		sort(edgeList.begin(), edgeList.end());

		UnionFind UF(P);
		vector<double> cost;

		for(int a = 0; a < edgeList.size(); a++){
			if(!UF.isSameSet(edgeList[a].second.first, edgeList[a].second.second)){
				UF.unionSet(edgeList[a].second.first, edgeList[a].second.second);

				cost.push_back(edgeList[a].first);
			}
		}

		sort(cost.begin(), cost.end(), greater<double>());

		printf("%.2lf\n", cost[S - 1]);
	}
}
*/