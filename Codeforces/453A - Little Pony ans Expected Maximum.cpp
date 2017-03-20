#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double ans=0;

int main(){
	double m, n;
	cin >> m >> n;
	for(double a=1;a<=m;a++)
		ans+=a*(pow((a/m), n)-pow(((a-1)/m), n));
	cout << fixed << setprecision(12) << ans << "\n";
}