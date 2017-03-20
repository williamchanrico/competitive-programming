#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

#define INF 0x3f3f3f3f

int n, data[5005], mins=INF, ans;
string kamus[5005], query;

int hitung(char x, char y){
	if(x<y) return hitung(y, x);
	if(x==y) return 0;
	return min(x-y, (int)y+26-(int)x);
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	data[5004]=INF;
	cin >> n; 
	for(int a=0;a<n;a++) data[a]=0;
	for(int a=0;a<n;a++) cin >> kamus[a];
	cin >> query;
	for(int a=0, sz=query.size();a<sz;a++){
		for(int b=0;b<n;b++){
			if(kamus[b].size()-1>=a){
				data[b]+=hitung(query[a], kamus[b][a]);
				ans=((data[b]<data[ans])?b:ans);
			}
		}
		cout << kamus[ans].substr(0, a+1) << endl;
		ans=5004;
	}
}
