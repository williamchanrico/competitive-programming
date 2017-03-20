#include <bits/stdc++.h>

class Interval{
public:
	double left;
	double right;
};

bool cmp(const Interval &x, const Interval &y){
	return x.left < y.left;
}

int main(){
	// freopen("in.txt", "r", stdin);
	int inputN;
	int inputL;
	int inputW;

	while(scanf("%d%d%d", &inputN, &inputL, &inputW) == 3){
		std::vector<Interval> v;
		Interval interval;

		for(int a = 0; a < inputN; a++){
			double inputPos;
			double inputRadius;

			scanf("%lf%lf", &inputPos, &inputRadius);

			if(inputRadius < (inputW / 2.0)) continue;

			double dx = sqrt((inputRadius * inputRadius) - ((inputW / 2.0) * (inputW / 2.0)));

			interval.left = inputPos - dx;
			interval.right = inputPos + dx;

			v.push_back(interval);
		}


		std::sort(v.begin(), v.end(), cmp);
		
		int ans = 0;
		double reached = 0;

		while(reached < inputL){
			double currReached = reached;
			int maxReachedIdx = -1;
			
			for(int a = 0, len = v.size(); a < len; a++){
				if(v[a].left > reached) break;
				
				if(v[a].right > currReached){
					maxReachedIdx = a;
					currReached = v[a].right;
				}
			}

			if(maxReachedIdx == -1) break;
			++ans;
			reached = currReached;
		}

		if(reached < inputL) printf("-1\n");
		else printf("%d\n", ans);
	}

}