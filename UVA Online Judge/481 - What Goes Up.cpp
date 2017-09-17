#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

vector<int> v, tail(100000, INF);
int memo[100000], p[100000];

int lis(){
	int len = 0;

	for(int a = 0; a < v.size(); a++){
		int low = 1;
		int high = len;

		while(low <= high){
			int mid = ceil((low + high) / 2.0);

			if(v[tail[mid]] < v[a])
				low = mid + 1;
			else
				high = mid - 1;
		}

		p[a] = tail[low - 1];
		tail[low] = a;

		if(low > len)
			len++;
	}

	return len;
}

void printLis(int idx, int count){
	if(count == 0)
		return;

	printLis(p[idx], count - 1);

	printf("%d\n", v[idx]);
}

int main(){
	int inp;

	while(scanf("%d", &inp) != EOF){
		v.push_back(inp);
	}

	int ans = lis();

	printf("%d\n-\n", ans);

	printLis(tail[ans], ans);
}

/* O(n^2) TLE approach

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int memo[100000], p[100000];

void dp(){
	for(int a = 0; a < v.size(); a++){
		memo[a] = 1;

		for(int b = 0; b < a; b++){
			if(v[a] > v[b]){
				if(memo[a] <= 1 + memo[b]){
					memo[a] = 1 + memo[b];
					p[a] = b;
				}
			}
		}
	}
}

void printLis(int idx){
	if(idx == 0){
		printf("%d\n", v[idx]);
		
		return;
	}

	printLis(p[idx]);

	printf("%d\n", v[idx]);
}

int main(){
	int inp;

	while(scanf("%d", &inp) != EOF){
		v.push_back(inp);
	}

	dp();

	int maxLen = *max_element(memo, memo + v.size());

	printf("%d\n-\n", maxLen);

	for(int a = v.size() - 1; a >= 0; a--){
		if(memo[a] == maxLen){
			printLis(a);

			break;
		}
	}
}

*/