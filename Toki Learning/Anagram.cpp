#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector< pair<string, string> > v;
map<string, pair<int, string> > m;
string ans, inp, temp;
int n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n; cin.ignore();
	for(int a=0;a<n;a++){
		getline(cin, inp);
		temp=inp; sort(temp.begin(), temp.end());
		if(m.count(temp)==0){ m[temp].first=1; m[temp].second=inp; }
		else{ m[temp].first++; if(inp<m[temp].second) m[temp].second=inp; }
		v.push_back(make_pair(inp, temp));
	}
	sort(v.begin(), v.end());
	int maks=-1;
	for(map<string, pair<int, string> >::iterator it=m.begin();it!=m.end();it++)
		if(maks < it->second.first){ maks=it->second.first; ans=it->first; }
		else if(maks == it->second.first){ if(it->second.second < m[ans].second) ans=it->first; }

	if(maks>1) cout << maks << "\n";
	else{ cout << "TIDAK ADA\n"; return 0; }
	for(int a=0, sz=v.size();a<sz;a++)
		if(ans==v[a].second) cout << v[a].first << "\n";
	
}