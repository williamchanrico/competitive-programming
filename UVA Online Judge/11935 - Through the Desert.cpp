#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define EPS 1e-9

vector<string> v;

bool valid(double maxFuel)
{
    string inpStr;
    double remFuel = maxFuel;
    int inpNum, pos = 0, leak = 0, goal = INF, consumption = 0;

    for (int a = 0; a < v.size(); a++) {
        stringstream ss(v[a]);

        ss >> inpNum >> inpStr;

        int dist = inpNum - pos;

        remFuel -= (consumption * dist / 100.0) + (leak * dist);

        if (remFuel < 0)
            return false;

        pos = inpNum;

        if (inpStr == "Goal")
            return true;
        else if (inpStr == "Leak")
            leak++;
        else if (inpStr == "Mechanic")
            leak = 0;
        else if (inpStr == "Gas")
            remFuel = maxFuel;
        else if (inpStr == "Fuel")
            ss >> inpStr >> consumption;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string inp;

    while (getline(cin, inp)) {

        if (inp == "0 Fuel consumption 0")
            break;

        v.push_back(inp);

        if (inp.find("Goal") != string::npos) {
            double lo = 0.0, hi = 100000.0, ans;

            while (fabs(hi - lo) > EPS) {
                double mid = (lo + hi) / 2.0;

                if (valid(mid))
                    ans = hi = mid;
                else
                    lo = mid;
            }

            cout << fixed << setprecision(3) << ans << "\n";

            v.clear();
        }
    }
}