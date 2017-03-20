#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > v;
map<int, int> m;

bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.second == y.second) return x.first>y.first;
	return x.second<y.second;
}

int main(){
	string x;
	bool virgin=false;
	while(cin>>x){
		if(virgin)cout << "\n";
		virgin=true;
		for(int a=0, sz=x.size();a<sz;a++)
			m[x[a]]++;
		for(map<int, int>::iterator it=m.begin();it!=m.end();it++)
			v.push_back(make_pair(it->first, it->second));
		sort(v.begin(), v.end(), cmp);
		for(int a=0;a<v.size();a++)
			cout << v[a].first << " " << v[a].second << "\n";
		v.clear();
		m.clear();
	}
}