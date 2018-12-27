#include <bits/stdc++.h>
using namespace std;

double panjang(double x1, double y1, double x2, double y2)
{
    double x = abs(x2 - x1);
    x *= x;
    double y = abs(y2 - y1);
    y *= y;
    return sqrt(x + y);
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double sisiMaks = max(panjang(x1, y1, x2, y2), panjang(x2, y2, x3, y3));
    sisiMaks = max(sisiMaks, panjang(x3, y3, x1, y1));
    double luas = abs(x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
    printf("%.6lf\n", (2 * luas) / sisiMaks);
}

/*
#include <bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
	point(){ x=y=0; }
	point(double _x, double _y):x(_x), y(_y){}
	bool operator < (point other) const{
		if(fabs(x-other.x)>1e-9)
			return x<other.x;
		return y<other.y;
	}
};

double hypot(double dx, double dy){
	return sqrt(dx*dx+dy*dy);
}

double dist(point p1, point p2){
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

int main(){
	vector<point> v;
	int x, y;
	for(int a=0;a<3;a++){
		scanf("%d %d", &x, &y);
		v.push_back(point(x, y));
	}
	double sisiMaks=-1.0;
	for(int a=0;a<3;a++)
		for(int b=a+1;b<3;b++)
			sisiMaks=max(sisiMaks, dist(v[a], v[b]));
	double luas=0.0, x1, x2, y1, y2;
	for(int a=0;a<3;a++){
		x1=v[a].x; 
		y1=v[(a+1)%3].y;
		x2=v[(a+1)%3].x; 
		y2=v[a].y;
		luas+=(x1*y1-x2*y2);
	}
	luas=fabs(luas/2.0);
	printf("%.6lf\n", 2*luas/sisiMaks);
}
*/