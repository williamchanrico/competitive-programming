#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector< pair<int, int> > v;
int n, x, y;
double ans=10000001, save=0, temp;

double hitung(pair<int, int> &x, pair<int, int> &y, pair<int, int> &z){
	double a, b, c, s;
	a=sqrt(pow(fabs(y.first-x.first), 2)+pow(fabs(y.second-x.second), 2));
	b=sqrt(pow(fabs(y.first-z.first), 2)+pow(fabs(y.second-z.second), 2));
	c=sqrt(pow(fabs(z.first-x.first), 2)+pow(fabs(z.second-x.second), 2));
	s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool sama(double x, double y){ return (fabs(x-y)<0.01); }

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
			for(int c=b+1;c<n;c++){
				temp=hitung(v[a], v[b], v[c]);
				if(sama(ans, temp)) save=ans;
				else if(!sama(temp, 0)) ans=min(ans, temp);
			}
	if(sama(ans, save) || sama(ans, 10000001)) printf("-1.00\n");
	else printf("%.02lf\n", ans);
}