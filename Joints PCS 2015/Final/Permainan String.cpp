#include <bits/stdc++.h>
using namespace std;

int hitung(string key, string x){
	int ans = 0;
	for(int a = 0, sz = x.size(); a < sz; a++){
		int idxKey = 0;
		bool moved = false;

		while(a < sz && key[idxKey] == x[a]){
			moved = true;
			a++;
			ans++;
			idxKey++;
			
			if(idxKey == key.size())
				idxKey = 0;
		}

		if(moved)
			a--;
	}
}

int main(){
	int G = 0, P = 0;
	bool gareng = true;
	string s, ss, temp = "";

	getline(cin, s);
	s += "#";

	getline(cin, ss);
	
	for(int a = 0, sz = s.size(); a < sz; a++){
		if(s[a] >= 'A' && s[a] <= 'Z'){
			temp += s[a];
		}else{
			//cout << "Potong " << (gareng ? "Gareng " : "Petruk ") << temp;
			if(gareng){
				G += hitung(ss, temp);
				temp = "";
				gareng = !gareng;
			}else{
				P += hitung(ss, temp);
				temp = "";
				gareng = !gareng;
			}
			//cout << " " << (!gareng?G:P) << "\n";
			while((s[a] < 'A' || s[a] > 'Z') && a < sz)
				a++;
			a--;
		}
	}
	//cout << "Gareng = " << G << "\nPetruk = " << P << "\n";
	cout << (G == P ? "Seri" : (G > P ? "Gareng" : "Petruk")) << "\n";
}