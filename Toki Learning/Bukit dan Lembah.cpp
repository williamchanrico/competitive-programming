#include <bits/stdc++.h>
using namespace std;

int main(){
	long long ans=-1, inp, target, last;
	cin >> inp;
	target=inp;
	cin >> inp;
	last=inp;
	bool status = (last>target?1:0);
	while(cin >> inp){
		if(status && inp>=last){
			last=inp;
		}else if(status && inp<last){
			ans=max(ans, last-target);
			target=last;
			last=inp;
			status=!status;
		}else if(!status && inp<=last){
			last=inp;
		}else if(!status && inp>last){
			ans=max(ans, target-last);
			target=last;
			last=inp;
			status=!status;
		}
	}
	if(status) ans=max(ans, last-target); else ans=max(ans, target-last);
	cout << ans << '\n';
}
