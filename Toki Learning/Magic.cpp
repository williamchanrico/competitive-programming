#include <bits/stdc++.h>
using namespace std;

int n, data[15][15];

int main(){
	cin >> n;
	for(int a=0;a<n;a++)
		cin >> data[a][0];
	for(int a=0;a<n-1;a++)
		for(int b=n-1-a;b>0;b--)
			data[b-1][a+1]=data[b][a]-data[b-1][a];
	for(int a=0;a<n;a++)
		if(a==n-1) cout << data[0][a] << "\n";
		else cout << data[0][a] << " ";
}