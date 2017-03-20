#include <bits/stdc++.h>
using namespace std;

int fibo[10000];

int fib(int x){
	if(fibo[x] != -1)
		return fibo[x];

	return fibo[x] = fib(x - 1) + fib(x - 2);
}

int main(){
	long long ans = 0;
	
	memset(fibo, -1, sizeof(fibo));

	fibo[0] = 1;
	fibo[1] = 2;
	
	for(int a = 0; fib(a) < 4000000; a++){
		cout << a << " " << fib(a) << "\n";
		ans += (fib(a) % 2 == 0) ? fib(a) : 0;
	}

	cout << ans << "\n";
}