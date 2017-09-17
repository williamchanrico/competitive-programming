#include <bits/stdc++.h>
using namespace std;

int main(){
	int T = 1, C, S;

	while(scanf("%d %d", &C, &S) != EOF){
		int inp;
		vector<int> v;
		vector<vector<int> > chamber(C);

		for(int a = 0; a < S; a++){
			scanf("%d", &inp);

			v.push_back(inp);
		}

		for(int a = 0; a < (2 * C) - S; a++)
			v.push_back(0);

		int sum = accumulate(v.begin(), v.end(), 0);

		double A = (double) sum / C;

		sort(v.begin(), v.end());

		for(int a = 0, b = v.size() - 1; a <= b; a++, b--){
			if(v[a] != 0)
				chamber[a % C].push_back(v[a]);
			if(v[b] != 0)
				chamber[a % C].push_back(v[b]);
		}

		double ans = 0;

		for(int a = 0; a < chamber.size(); a++){
			double sum = 0;

			for(int b = 0; b < chamber[a].size(); b++)
				sum += chamber[a][b];

			ans += fabs(sum - A);
		}

		printf("Set #%d\n", T++);

		for(int a = 0; a < chamber.size(); a++){
			printf(" %d:", a);

			for(int b = 0; b < chamber[a].size(); b++)
				printf(" %d", chamber[a][b]);
			printf("\n");
		}

		printf("IMBALANCE = %.5lf\n\n", ans);
	}
}
