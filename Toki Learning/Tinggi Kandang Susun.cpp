#include <stdio.h>
#include <algorithm>
using namespace std;

long long n, k, ans=1, maks=0, temp; //ans=1 karena lantai paling dasar 1 cm

int main(){
	scanf("%lld %lld", &n, &k);
	for(long long a=1;a<=n;a++){
		scanf("%lld", &temp); maks=max(maks, temp);
		if(a%k==0){ ans+=maks+1; maks=0; }
	}
	if(n%k!=0) ans+=maks+1; //maks + 1 karena tiap lantai beratap 1 cm / sebagai lantai 1 cm pada tingkat selanjutnya
	printf("%lld\n", ans);
}
