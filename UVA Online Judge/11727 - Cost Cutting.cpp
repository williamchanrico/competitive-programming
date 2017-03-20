#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int T, data[5];
	scanf("%d", &T);
	for(int a=1;a<=T;a++){
		for(int b=0;b<3;b++)
			scanf("%d", &data[b]);
		sort(data, data+3);
		printf("Case %d: %d\n", a, data[1]);
	}
}