#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int N, temp;

int main(){
	scanf("%d", &N);
	for(int a=0;a<N;a++){
		scanf("%d", &temp);
		if(m.count(temp)==0) printf("%d\n", temp);
		m[temp]=1;
	}
}