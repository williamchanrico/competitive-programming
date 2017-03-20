#include <bits/stdc++.h>

int main(){
	// freopen("in.txt", "r", stdin);
	int T;

	scanf("%d", &T);

	while(T--){
		int inputM;
		int inputL;
		int inputR;
		std::vector<std::pair<int, int> > v;

		scanf("%d", &inputM);

		while(scanf("%d %d", &inputL, &inputR) && inputL | inputR){
			v.push_back(std::make_pair(inputL, inputR));
		}

		std::sort(v.begin(), v.end());

		std::vector<std::pair<int, int> > vAns;
		int reached = 0;

		while(reached < inputM){
			int newReached = reached;
			int newSegmentIdx = -1;

			for(int a = 0, len = v.size(); a < len; a++){
				if(v[a].first > reached) break;

				if(v[a].second > newReached){
					newReached = v[a].second;
					newSegmentIdx = a;
				}
			}

			if(newSegmentIdx == -1) break;
			reached = newReached;
			vAns.push_back(v[newSegmentIdx]);
		}

		if(reached < inputM){
			printf("0\n");
		}else{
			printf("%d\n", vAns.size());
			for(int a = 0, len = vAns.size(); a < len; a++){
				printf("%d %d\n", vAns[a].first, vAns[a].second);
			}
		}
		
		if(T != 0) printf("\n");
	}
}