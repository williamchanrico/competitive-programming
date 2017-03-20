#include <iostream>
using namespace std;

string inp1, inp2;

int hitung(int x, int y){
	int ans=0;
	for(int a=0, b=x;b<=y;a++, b++)
		if(inp1[a]!=inp2[b])
			ans++;
	return ans;
}

int main(){
	getline(cin, inp1);
	getline(cin, inp2);
	int counter=0, pos=inp1.size()-1, ans=100;
	while(pos<inp2.size()){
		//cout << hitung(counter, pos) << " " << ans << endl;
		ans=min(ans, hitung(counter, pos));
		counter++;
		pos=counter+inp1.size()-1; //cout << "pos skrg " << pos << " " << "counter " << counter << endl;
	}
	cout << ans << "\n";
}