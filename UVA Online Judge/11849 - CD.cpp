#include <stdio.h>
#include <set>
using namespace std;

set<int> s;

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m), n|m){
		int inp;
		for(int a=0;a<n;a++){
			scanf("%d", &inp);
			s.insert(inp);
		}
		for(int a=0;a<m;a++){
			scanf("%d", &inp);
			s.insert(inp);
		}
		printf("%d\n", (n+m)-s.size());
		s.clear();
	}
}