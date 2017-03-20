#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	int inp;
	int mode;
	int freqMode = -1;
	map<int, int> m;

	scanf("%d", &N);

	while(N--){
		scanf("%d", &inp);

		if(!m.count(inp))
			m[inp] = 1;
		else
			m[inp]++;

		if(m[inp] >= freqMode){
			freqMode = m[inp];
			mode = inp;
		}
		
		if(N == 0){
			for(map<int, int>::iterator it=m.begin(); it != m.end(); it++){
				if(it->first != mode && it->second == freqMode){
					printf("BINGUNG\n");
					return 0;
				}
			}
			printf("%d\n", mode);
		}
	}
}