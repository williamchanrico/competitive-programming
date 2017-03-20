#include <stdio.h>
#include <string.h>
using namespace std;
long long data[1010];

long long func(long long x){
	if(data[x]!=-1)
		return data[x];
	data[x]=(func(x-1)+func(x-3))%1000000;
	return data[x];
}
int main(){
	memset(data, -1, sizeof(data));
	data[0]=data[1]=data[2]=1;
	int n;
	scanf("%d", &n);
	printf("%lld\n", func(n));
}

