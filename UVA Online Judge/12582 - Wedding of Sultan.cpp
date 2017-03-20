#include <bits/stdc++.h>
using namespace std;

int T;
string inp;
char past;
map<char, bool> visited;
map<char, char> parent;
map<char, int> degree;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int CASE=1;CASE<=T;CASE++){
		cin >> inp;
		for(int a=0, sz=inp.size();a<sz;a++){
			degree[inp[a]]=0;
			visited[inp[a]]=false;
		}
		past=inp[0]; visited[inp[0]]=true; parent[inp[0]]=inp[0];
		for(int a=1, sz=inp.size();a<sz;a++){
			if(!visited[inp[a]]){
				visited[inp[a]]=true;
				parent[inp[a]]=past;
				degree[inp[a]]++; degree[past]++;
				past=inp[a];
			}else{
				past=parent[inp[a]];
			}
		}
		cout << "Case " << CASE << "\n";
		for(map<char, int>::iterator it=degree.begin();it!=degree.end();it++)
			cout << it->first << " = " << it->second << "\n";
		degree.clear(); parent.clear(); visited.clear();
	}
}