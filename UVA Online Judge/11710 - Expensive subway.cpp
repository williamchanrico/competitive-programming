#include <bits/stdc++.h>
using namespace std;

map<string, int> station;
vector<pair<long long, pair<int, int>>> EdgeList;
string inp;
int S, C;
long long tmp;

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSet;

public:
    UnionFind(int x)
    {
        p.assign(x, 0);
        rank.assign(x, 0);
        numSet = x;
        setSize.assign(x, 1);
        for (int a = 0; a < x; a++)
            p[a] = a;
    }
    int findSet(int x) { return (p[x] == x) ? x : findSet(p[x]); }
    bool isSameSet(int x, int y) { return (findSet(x) == findSet(y)); }
    void unionSet(int x, int y)
    {
        numSet--;
        int a = findSet(x), b = findSet(y);
        if (rank[a] < rank[b]) {
            p[a] = b;
            setSize[b] += setSize[a];
        } else {
            p[b] = a;
            setSize[a] += setSize[b];
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int numDisjointSets() { return numSet; }
    int SizeOfSet(int x) { return setSize[findSet(x)]; }
};

int main()
{
    while (scanf("%d %d", &S, &C), S || C) {
        cin.ignore();
        for (int a = 0; a < S; a++) {
            getline(cin, inp);
            station[inp] = a;
        }
        for (int a = 0; a < C; a++) {
            int x, y;
            cin >> inp;
            x = station[inp];
            cin >> inp;
            y = station[inp];
            cin >> tmp;
            EdgeList.push_back(make_pair(tmp, make_pair(x, y)));
        }
        cin >> inp;
        tmp = station[inp];
        sort(EdgeList.begin(), EdgeList.end());
        long long mst_cost = 0;
        UnionFind UF(S);
        for (int a = 0; a < C; a++) {
            if (!UF.isSameSet(EdgeList[a].second.first, EdgeList[a].second.second)) {
                UF.unionSet(EdgeList[a].second.first, EdgeList[a].second.second);
                mst_cost += EdgeList[a].first;
            }
        }
        if (UF.numDisjointSets() == 1)
            cout << mst_cost << "\n";
        else
            cout << "Impossible\n";
        EdgeList.clear();
        station.clear();
        /*
		for(int a=0;a<C;a++)
			cout << EdgeList[a].first << " " << EdgeList[a].second.first << " " << EdgeList[a].second.second << "\n";
		*/
    }
}