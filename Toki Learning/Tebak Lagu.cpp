#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
string inp, tmp, symbols[26]={"c.", "c#", "d.", "d#", "e.", "f.", "f#", "g.", "g#", "a.", "a#", "b.", "C.", "C#", "D.", "D#", "E.", "F.", "F#", "G.", "G#", "A.", "A#", "B."};
int n;

void trans(string &x){
	string ch, holder, ans;
	bool naik;
	for(int a=0, sz=x.size()-2;a<sz;a+=2){
		int tmp=m[x.substr(a, 2)]-m[x.substr(a+2, 2)];
		naik=true;
		if(tmp>0) naik=false;
		else if(tmp<0) naik=true;
		stringstream ss;
		ss << tmp;
		ss >> holder;
		ch=(naik)?"^":"_";
		ans+=ch+holder; if(a!=sz-1) ans+=" ";
	}
	x=ans;
}

int main(){
	bool found=false;
	int ans;
	for(int a=0;a<24;a++)
		m[symbols[a]]=a+1;
	/* for(map<string, int>::iterator it=m.begin();it!=m.end();it++)
		cout << it->first << " " << it->second << "\n"; */
	getline(cin, inp);
	trans(inp);
	//cout << inp << endl;
	cin >> n; cin.ignore();
	for(int a=1;a<=n;a++){
		getline(cin, tmp);
		trans(tmp);
		//cout << tmp << endl;
		if(tmp.find(inp)!=string::npos){
			if(!found){ ans=a; found=true; }
		}
	}
	if(found) cout << ans << "\n";
	else cout << "#\n";
}