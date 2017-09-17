#include <bits/stdc++.h>
using namespace std;

int main(){
	char str[110000];

	while(scanf("%s", str) != EOF){
		list<char> text;
		auto it = text.begin();

		for(int a = 0; str[a]; a++){
			if(str[a] == '[')
				it = text.begin();
			else if(str[a] == ']')
				it = text.end();
			else
				text.insert(it, str[a]);	
		}

		copy(text.begin(), text.end(), ostream_iterator<char>(cout, ""));

		printf("\n");
	}
}