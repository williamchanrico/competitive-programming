#include <bits/stdc++.h>

int main(){
	// freopen("in.txt", "r", stdin);
	int T;

	scanf("%d", &T);

	while(T--){
		int inputN;
		int ans = 0;
		int startIdx = 0;
		std::map<long long, int> m;

		scanf("%d", &inputN);

		for(int a = 0; a < inputN; a++){
			long long temp;

			scanf("%lld", &temp);

			if(m.count(temp) == 0 || m[temp] < startIdx){
				m[temp] = a;
			}else{
				ans = std::max(ans, a - startIdx);
				startIdx = m[temp] + 1;
				m[temp] = a;
			}
		}
		
		ans = std::max(ans, inputN - startIdx);

		printf("%d\n", ans);

		m.clear();
	}
}