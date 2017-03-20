#include <iostream>
using namespace std;

long long T, inp, awal, temp, ans=0;
bool check=false, gagal=false;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	cin >> inp;
	awal=inp; temp=inp;
	for(long long a=1;a<T;a++){
		cin >> inp;
		if(inp<temp && check){
			gagal=true;
		}else{
			if(inp<temp) check=true;
			if(check) ans++;
			temp=inp;
		}
	}
	if(gagal){ cout << "-1\n"; return 0; }
	if(check){
		if(inp<awal) cout << ans << "\n";
		else cout << "-1\n";
	}else{
		cout << "0\n";
	}
}