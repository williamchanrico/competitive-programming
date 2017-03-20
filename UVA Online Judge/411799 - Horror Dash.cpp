#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int T, n, x=1, arr[10000];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int a=0;a<n;a++)
			scanf("%d", &arr[a]);
		sort(arr, arr+n);
		printf("Case %d: %d\n", x, arr[n-1]);
		x++;
	}
}