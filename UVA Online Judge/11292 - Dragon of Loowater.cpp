#include <bits/stdc++.h>

int main(){
	// freopen("in.txt", "r", stdin);
	int n;
	int m;

	while(scanf("%d%d", &n, &m) && n | m){
		std::vector<int> vN(n);
		std::vector<int> vM(m);

		for(int a = 0; a < n; a++) scanf("%d", &vN[a]);
		for(int a = 0; a < m; a++) scanf("%d", &vM[a]);

		std::sort(vN.begin(), vN.end());
		std::sort(vM.begin(), vM.end());

		int monster = 0;
		int knight = 0;
		int ans = 0;

		while(monster < n && knight < m){
			while(vN[monster] > vM[knight] && knight < m) knight++;

			if(knight == m) break;

			ans += vM[knight];

			monster++;
			knight++;
		}

		if(monster == n) printf("%d\n", ans);
		else printf("Loowater is doomed!\n");
	}
}