#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

class Point {
public:
    int X, Y;

    Point() {}

    Point(int x, int y)
    {
        X = x;
        Y = y;
    }

    bool operator==(Point other) const
    {
        return (fabs(X - other.X) < EPS && (fabs(Y - other.Y) < EPS));
    }
};

class Vec {
public:
    double X, Y;

    Vec(double x, double y)
    {
        X = x;
        Y = y;
    }
};

Point pivot(0, 0);

Vec toVec(Point x, Point y)
{
    return Vec(y.X - x.X, y.Y - x.Y);
}

double cross(Vec x, Vec y)
{
    return x.X * y.Y - x.Y * y.X;
}

bool ccw(Point p, Point q, Point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

double dist(Point x, Point y)
{
    return hypot(x.X - y.X, x.Y - y.Y);
}

bool collinear(Point p, Point q, Point r)
{
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool angleCmp(Point x, Point y)
{
    if (collinear(pivot, x, y))
        return dist(pivot, x) < dist(pivot, y);

    double d1x = x.X - pivot.X, d1y = x.Y - pivot.Y;
    double d2x = y.X - pivot.X, d2y = y.Y - pivot.Y;

    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<Point> CH(vector<Point> P)
{
    int a, b, n = (int)P.size();

    if (n <= 3) {
        if (!(P[0] == P[n - 1]))
            P.push_back(P[0]);

        return P;
    }

    int P0 = 0;

    for (a = 1; a < n; a++)
        if (P[a].Y < P[P0].Y || (P[a].Y == P[P0].Y && P[a].X > P[P0].X))
            P0 = a;

    Point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;

    pivot = P[0];

    sort(++P.begin(), P.end(), angleCmp);

    vector<Point> S;

    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);

    a = 2;

    while (a < n) {
        b = (int)S.size() - 1;

        if (ccw(S[b - 1], S[b], P[a]))
            S.push_back(P[a++]);
        else
            S.pop_back();
    }

    return S;
}

int main()
{
    int Q;
    vector<Point> vP;

    scanf("%d", &Q);

    while (Q--) {
        int cmd, x1, y1, x2, y2;

        scanf("%d", &cmd);

        if (cmd == 0) {

            scanf("%d %d", &x1, &y1);

            vP.push_back(Point(x1, y1));

        } else {

            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            vector<Point> ans = CH(vP);

            int idx1, idx2, cw = 0, ccw = 0;

            for (int a = 0; a < ans.size() - 1; a++) {
                if (ans[a] == Point(x1, y1))
                    idx1 = a;
            }

            for (int a = 1; a < ans.size(); a++) {
                if (ans[a] == Point(x2, y2))
                    idx2 = a;
            }

            int sum = 0;

            for (int a = 0; a < ans.size() - 1; a++)
                sum += (ans[a + 1].X - ans[a].X) * (ans[a + 1].Y + ans[a].Y);

            if (idx1 < idx2) {
                cw = idx2 - idx1;
                ccw = ans.size() - 1 - cw;
            } else {
                ccw = idx1 - idx2;
                cw = ans.size() - 1 - ccw;
            }

            if (sum < 0)
                swap(cw, ccw);

            if (cw < ccw)
                printf("CCW\n");
            else
                printf("CW\n");
        }
    }
}
