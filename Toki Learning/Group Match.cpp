#include <bits/stdc++.h>
using namespace std;

int T, n, inp[10], score[10]={0, 0, 0, 0};

bool bt(int x, int y){
	bool ret=false; 
	if(x==(n-1)){ 
		ret=true; 
		for(int a=0;a<n;a++)
			if(inp[a]!=score[a]){ ret=false; break; }
	}else if(y==n){
		ret=(ret || bt(x+1, x+2));
	}else{
		score[x]+=3;
		ret=(ret || bt(x, y+1));
		score[x]-=3;
		
		score[x]++;
		score[y]++;
		ret=(ret || bt(x, y+1));
		score[x]--;
		score[y]--;
		
		score[y]+=3;
		ret=(ret || bt(x, y+1));
		score[y]-=3;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> n;
		for(int a=0;a<n;a++)
			cin >> inp[a];
		if(bt(0,1)) cout << "YES\n";
		else cout << "NO\n";
	}
}