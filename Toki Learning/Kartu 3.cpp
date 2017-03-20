#include <bits/stdc++.h>
using namespace std;

int n;
char grid[10][10], inp[10];

void check(){
	bool A=false, B=false;
	for(int a=0;a<3;a++){
		if(grid[a][0]=='A' && grid[a][1]=='A' && grid[a][2]=='A') A=true;
		else if(grid[a][0]=='B' && grid[a][1]=='B' && grid[a][2]=='B') B=true;
		if(grid[0][a]=='A' && grid[1][a]=='A' && grid[2][a]=='A') A=true;
		else if(grid[0][a]=='B' && grid[1][a]=='B' && grid[2][a]=='B') B=true;
	}
	if(grid[0][0]=='A' && grid[1][1]=='A' && grid[2][2]=='A') A=true;
	else if(grid[0][0]=='B' && grid[1][1]=='B' && grid[2][2]=='B') B=true;
	if(grid[0][2]=='A' && grid[1][1]=='A' && grid[2][0]=='A') A=true;
	else if(grid[0][2]=='B' && grid[1][1]=='B' && grid[2][0]=='B') B=true;
	if(A) cout << "A\n";
	else if(B) cout << "B\n";
	else cout << "S\n";
}

int main(){
	cin >> n;
	for(int a=0;a<n;a++){
		for(int b=0;b<3;b++){
			cin >> inp;
			grid[b][0]=inp[1];
			grid[b][1]=inp[3];
			grid[b][2]=inp[5];
		}
		check();
	}
	
}
