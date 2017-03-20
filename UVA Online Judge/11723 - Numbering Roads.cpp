#include <bits/stdc++.h>
using namespace std;

double R, N;

int main(){
	int Case=1, ans;
	while(scanf("%lf %lf", &R, &N), R||N){
		ans=ceil((R-N)/N);
		if(ans<=26) printf("Case %d: %d\n", Case++, ans);
		else printf("Case %d: impossible\n", Case++);
	}
}