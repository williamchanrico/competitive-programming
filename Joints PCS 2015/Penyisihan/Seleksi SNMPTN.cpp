// Fors

#include <bits/stdc++.h>
using namespace std;

struct db{
	int value[6];
};

vector<db> v;
map<string, int> m;
int priority[6];

bool cmp(db x, db y){
	for(int a = 0; a < 5; a++)
		if(x.value[priority[a]] != y.value[priority[a]])
			return x.value[priority[a]] > y.value[priority[a]];
	return x.value[5] > y.value[5];
}

int main(){
	int N, vv[6];
	string tmp;

	m["MTK"] = 0;
	m["BIO"] = 1;
	m["KIM"] = 2;
	m["FIS"] = 3; 
	m["IND"] = 4;
	m["ING"] = 5;

	scanf("%d", &N);

	for(int a = 0; a < N; a++){
		scanf("%d %d %d %d %d %d", &vv[0], &vv[1], &vv[2], &vv[3], &vv[4], &vv[5]);

		db lol;
		lol.value[0]=vv[0]; lol.value[1]=vv[1]; lol.value[2]=vv[2];
		lol.value[3]=vv[3]; lol.value[4]=vv[4]; lol.value[5]=vv[5];

		v.push_back(lol);
	}
	for(int a = 0; a < 6; a++){
		cin >> tmp;
		priority[a] = m[tmp];
	}

	sort(v.begin(), v.end(), cmp);

	for(int a = 0; a < N && a < 100; a++)
		printf("%d %d %d %d %d %d\n", v[a].value[0], v[a].value[1], v[a].value[2], v[a].value[3], v[a].value[4], v[a].value[5]);
}