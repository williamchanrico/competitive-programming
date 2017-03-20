#include <bits/stdc++.h>
using namespace std;
	
long long arr[20010], tmp, x, y , N;


int main(){
	arr[0] = 0;
	
	cin >> N;
	
	for(int a = 1; a < N; a++){
		cin >> tmp;
		arr[a] = arr[a - 1] + tmp;
	}
	
	cin >> tmp;

	for(int a = 0; a < tmp; a++){
		cin >> x >> y;

		if(x > y)
			swap(x, y);
		
		cout << arr[y - 1] - arr[x - 1] << "\n";
	}
}