#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string str;
	scanf("%d", &T);
	while(T--){
		cin >> str;
		int count=1, ans=0;
		for(int a=0, sz=str.size();a<sz;a++){
			if(str[a]=='O') ans+=count++;
			else count=1;
		}
		printf("%d\n", ans);
	}
}