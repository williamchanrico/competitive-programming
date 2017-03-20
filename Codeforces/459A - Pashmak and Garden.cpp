#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1!=x2 && y1!=y2 && abs(y1-y2)!=abs(x1-x2))
		cout << "-1\n";
	else if(x1==x2)
		cout << x1+abs(y2-y1) << " " << y1 << " " << x2+abs(y2-y1) << " " << y2 << "\n";
	else if(y1==y2)
		cout << x1 << " " << y1+abs(x2-x1) << " " << x2 << " " << y2+abs(x2-x1) << "\n";
	else
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
	return 0;
}