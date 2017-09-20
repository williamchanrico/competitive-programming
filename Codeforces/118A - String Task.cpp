#include <bits/stdc++.h>
using namespace std;

bool isVowel(char x){
	x = tolower(x);

	return (x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o' || x == 'y');
}

void process(char x){
	if(!isVowel(x))
		printf(".%c", tolower(x));
}

int main(){
	char str[110];

	scanf("%s", str);

	for_each(str, str + strlen(str), process);

	printf("\n");
}