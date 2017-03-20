#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("out.txt", "w", stdout);
	int T;
	bool virgin=true;
	while(scanf("%d", &T)!=EOF){
		if(!virgin) cout << "\n";
		map<string, int> m;
		vector<string> v;
		string tmp;
		for(int a=0;a<T;a++){
			cin >> tmp;
			v.push_back(tmp);
			m[tmp]=0;
		}
		for(int a=0;a<T;a++){
			int money, people;
			cin >> tmp >> money >> people;
			if(people!=0) m[tmp]+=(money%people)-money;
			for(int a=0;a<people;a++){
				cin >> tmp;
				m[tmp]+=(money/people);
			}
		}
		for(int a=0;a<T;a++)
			cout << v[a] << " " << m[v[a]] << "\n";
		virgin=false;
	}
}