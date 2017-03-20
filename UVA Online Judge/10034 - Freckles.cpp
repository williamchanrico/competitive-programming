#include <bits/stdc++.h>
using namespace std;

vector< pair< double, pair<int, int> > > EdgeList;
int T, n;
double x[110], y[110], dist[110][110];
string temp;

class UnionFind{
private:
	vector<int> p, rank;
public:
	UnionFind(int x){
		p.assign(x, 0);
		rank.assign(x, 0);
		for(int a=0;a<x;a++)
			p[a]=a;
	}
	int findSet(int x){ return (p[x]==x)?x:findSet(p[x]); }
	bool isSameSet(int x, int y){ return (findSet(x)==findSet(y)); }
	void unionSet(int x, int y){
		int a=findSet(x), b=findSet(y);
		if(rank[a]<rank[b]){
			p[a]=b;
		}else{
			p[b]=a;
			if(rank[a]==rank[b]) rank[a]++;
		}
	}
};

int main(){
	cin >> T; cin.ignore();
	while(T--){
		cin.ignore();
		cin >> n;
		for(int a=0;a<n;a++)
			cin >> x[a] >> y[a];
		for(int a=0;a<n;a++)
			for(int b=0;b<a;b++)
				dist[a][b]=sqrt((abs(x[a]-x[b])*abs(x[a]-x[b]))+(abs(y[a]-y[b])*abs(y[a]-y[b])));
		for(int a=0;a<n;a++)
			for(int b=0;b<a;b++)
				EdgeList.push_back(make_pair(dist[a][b], make_pair(a, b)));
		sort(EdgeList.begin(), EdgeList.end());
		double mst_cost=0;
		UnionFind UF(n);
		for(int a=0, sz=EdgeList.size();a<sz;a++){
			if(!UF.isSameSet(EdgeList[a].second.first, EdgeList[a].second.second)){
				UF.unionSet(EdgeList[a].second.first, EdgeList[a].second.second);
				mst_cost+=EdgeList[a].first;
			}
		}
		cout << fixed << setprecision(2) << mst_cost << "\n";
		if(T!=0) cout << "\n";
		EdgeList.clear();
	}
}