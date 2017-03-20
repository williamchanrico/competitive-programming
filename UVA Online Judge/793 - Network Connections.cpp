#include <bits/stdc++.h>
using namespace std;

class unionFind{
private:
	vector<int> p, rank;
	int numSet;
public:
	unionFind(int x){
		p.assign(x+1, 0);
		rank.assign(x+1, 0);
		numSet = x+1;
		for(int a = 1;a<=x;a++)
			p[a] = a;
	}
	int findSet(int x){ return (p[x] == x)?x:findSet(p[x]); }
	bool isSameSet(int x, int y){ return (findSet(x) == findSet(y)); }
	void unionSet(int x, int y){
		if(!isSameSet(x, y)){
			numSet--;
			int a = findSet(x), b = findSet(y);
			if(rank[a]>rank[b]){
				p[b] = a;
			}else{
				p[a] = b;
				if(rank[a] == rank[b]) rank[b]++;
			}
		}
	}
	int numDisjointSet(){ return numSet; }
};

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char inp1, str[256];
	int T, N, inp2, inp3;
	scanf("%d", &T);
	while(T--){
		int ans1 = 0, ans2 = 0;
		scanf("%d ", &N);
		unionFind UF(N);
		while(gets(str)){
			if(str[0] == '\0') break;
			sscanf(str, "%c %d %d", &inp1, &inp2, &inp3);
			if(inp1 == 'c'){
				UF.unionSet(inp2, inp3);
			}else{
				if(UF.isSameSet(inp2, inp3)) ans1++;
				else ans2++;
			}
		}
		printf("%d,%d\n", ans1, ans2);
		if(T)  printf("\n");
	}
}