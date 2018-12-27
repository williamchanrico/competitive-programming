#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> v;

bool comp(string x, string y)
{
    if (x[0] == y[0]) {
        for (int a = 1, sz = x.size(); a < sz; a++) {
            if (x[a] != y[a] && tolower(x[a]) != tolower(y[a])) {
                return tolower(x[a]) < tolower(y[a]);
            } else if (x[a] != y[a]) {
                return x[a] < y[a];
            }
        }
    } else if (x[0] != y[0] && tolower(x[0]) != tolower(y[0])) {
        return tolower(x[0]) < tolower(y[0]);
    } else {
        return x[0] < y[0];
    }
}

int main()
{
    int n;
    string inp;
    getline(cin, inp);
    stringstream myStream(inp);
    myStream >> n;
    while (n--) {
        getline(cin, inp);
        sort(inp.begin(), inp.end());
        do {
            v.push_back(inp);
        } while (next_permutation(inp.begin(), inp.end()));
        sort(v.begin(), v.end(), comp);
        for (int a = 0, sz = v.size(); a < sz; a++)
            cout << v[a] << endl;
        v.clear();
    }
}