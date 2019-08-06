#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;

    getline(cin, S);

    map<char, int> mCharCount;
    for (int a = 0, len = S.size(); a < len; a++) {
        ++mCharCount[S[a]];
    }

    int maxi = -1;
    int mini = 0x3f3f3f3f;
    set<int> countSet;
    map<int, int> mCountCount;
    for (auto it = mCharCount.begin(); it != mCharCount.end(); it++) {
        maxi = max(mCharCount[it->first], maxi);
        mini = min(mCharCount[it->first], mini);
        ++mCountCount[it->second];
        countSet.insert(it->second);
    }

    if (maxi == mini) {
        cout << "YES\n";
    } else if (maxi - mini == 1 && mCountCount[maxi] == 1 && countSet.size() == 2) {
        cout << "YES\n";
    } else if (mini == 1 && mCountCount[mini] == 1 && countSet.size() == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
