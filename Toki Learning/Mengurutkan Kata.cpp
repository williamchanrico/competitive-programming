#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string inp;
int N;

bool cmp(string x, string y){
	if(x.size()==y.size()) return x<y;
	return x.size()<y.size();
}

int main(){
	scanf("%d", &N); getchar();
	for(int a=0;a<N;a++){
		getline(cin, inp);
		v.push_back(inp);
	}
	sort(v.begin(), v.end(), cmp);
	for(int a=0;a<N;a++)
		cout << v[a] << "\n";
}