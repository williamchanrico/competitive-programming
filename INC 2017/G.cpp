#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, inp, maxi = -1;
	map<int, pair<int, int> > m;

	scanf("%d", &N);

	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){

			scanf("%d", &inp);

			if(!m.count(inp)){

				m[inp] = make_pair(a, b);

			}else{

				pair<int, int> u = m[inp];

				if(u.first <= a){
					if(u.second <= b)
						maxi = max(maxi, inp);

					m[inp] = make_pair(a, b);
				}
			}
		}
	}

	printf("%d\n", maxi);
}
