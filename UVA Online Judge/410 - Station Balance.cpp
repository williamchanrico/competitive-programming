#include <bits/stdc++.h>

int main(){
	// freopen("in.txt", "r", stdin);
	int set = 1;
	int inputC;
	int inputS;

	while(scanf("%d %d", &inputC, &inputS) != EOF){
		std::vector<int> v(1);

		for(int a = 0; a < inputS; a++){
			scanf("%d", &v[0]);
			v.push_back(v[0]);
		}

		for(int a = 0; a < (inputC * 2) - inputS; a++)
			v.push_back(0);

		std::sort(v.begin() + 1, v.end());

		int idx = 0;
		double imbalance = 0;
		double totalMass = 0;
		std::vector<std::vector<int> > ans(inputC);

		for(int a = 1, len = v.size(); a < len; a++)
			totalMass += v[a];

		double averageMass = totalMass / inputC;

		for(int a = 1, b = inputC * 2; a < b; a++, b--){
			if(v[a] != 0) ans[idx].push_back(v[a]);
			if(v[b] != 0) ans[idx].push_back(v[b]);
			idx = (idx + 1) % inputC;
		}

		for(int a = 0; a < inputC; a++){
			totalMass = 0;
			for(int b = 0, len = ans[a].size(); b < len; b++)
				totalMass += ans[a][b];
			imbalance += fabs(totalMass - averageMass);
		}

		printf("Set #%d\n", set++);

		for(int a = 0; a < inputC; a++){
			printf(" %d:", a);
			for(int b = 0, len = ans[a].size(); b < len; b++)
				printf(" %d", ans[a][b]);
			printf("\n");
		}
		printf("IMBALANCE = %.05lf\n\n", imbalance);
	}
}