#include <bits/stdc++.h>
using namespace std;

string inp;
int tmp, ans=0, siz;
bool valid=true;

int main(){
	cin >> tmp >> siz; tmp='0';
	for(int a=0;a<siz;a++){
		cin >> inp;
		if(valid){
			ans++;
			if(tmp>inp[0]) 
				valid=false;
		}
		tmp=inp[0];
	}
	cout << ans << "\n";
}
