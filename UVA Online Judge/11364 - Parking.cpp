#include <stdio.h>
#include <algorithm>
using namespace std;

int t, n, store[50], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans=0;
		scanf("%d", &n);
		for(int a=0;a<n;a++)
			scanf("%d", &store[a]);
		sort(store, store+n);
		for(int a=1;a<n;a++)
			ans+=(store[a]-store[a-1]);
		printf("%d\n", ans*2);
	}
}