#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main(){
	scanf("%d", &T);
	for(int CASE=1;CASE<=T;CASE++){
		int ans=0;
		scanf("%d %d", &n, &m);
		for(int a=n;a<=m;a++)
			if(a%2==1) ans+=a;
		printf("Case %d: %d\n", CASE, ans);
	}
}