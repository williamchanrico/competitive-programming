#include <bits/stdc++.h>
using namespace std;

class Point{
public:
	long long X, Y;

	Point(){}

	Point(int x, int y){
		X = x;
		Y = y;
	}

	bool operator<(const Point &p) const{
		return (X != p.X ? X < p.X : Y < p.Y);
	}
};

long long ccw(Point p, Point q, Point r){
	return (p.X * q.Y + q.X * r.Y + r.X * p.Y - 
		p.Y * q.X - q.Y * r.X - r.Y * p.X);
}

vector<Point> convexHullMonotoneChain(vector<Point> &p){
    int N = p.size(), K = 0;
    vector<Point> ans(2 * N);
    
    sort(p.begin(), p.end());
    
    for(int a = 0; a < N; a++){
        while(K >= 2 && ccw(ans[K - 2], ans[K - 1], p[a]) < 0)
        	K--;
        ans[K++] = p[a];
    }
    
    for(int a = N - 2, aa = K; a >= 0; a--){
        while(K > aa && ccw(ans[K - 2], ans[K - 1], p[a]) < 0)
        	K--;
        ans[K++] = p[a];
    }
    
    ans.resize(K - 1);

    return ans;
}

int main(){
	int TC;
	
	scanf("%d", &TC);

	while(TC--){
		int N, X, Y;
		vector<Point> vP;

		scanf("%d", &N);

		for(int a = 0; a < N; a++){
			scanf("%d %d %*c", &X, &Y);

			vP.push_back(Point(X, Y));
		}

		vector<Point> ans = convexHullMonotoneChain(vP);

		printf("%d\n", ans.size());

		for(int a = 0; a < ans.size(); a++)
			printf("%d %d\n", ans[a].X, ans[a].Y);
	}
}
