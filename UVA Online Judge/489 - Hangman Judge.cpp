#include <iostream>
#include <map>
using namespace std;

map<char, int> m;

void prepare()
{
    for (char a = 'a'; a <= 'z'; a++)
        m[a] = 0;
}

int main()
{
    string inp, inpp;
    int n;
    cin >> n;
    while (n != -1) {
        inp = "";
        inpp = "";
        prepare();
        int ans = 0, draw = 0;
        cin >> inp;
        cin >> inpp;
        for (int a = 0, sza = inpp.size(); a < sza; a++) {
            if (m[inpp[a]] != 1) {
                bool tr = false;
                for (int b = 0, szb = inp.size(); b < szb; b++) {
                    if (inpp[a] == inp[b]) {
                        inp[b] = '.';
                        tr = true;
                        ans++;
                    }
                    if (b == (szb - 1) && tr == false)
                        draw++;
                }
                m[inpp[a]] = 1;
            }

            if (draw == 7) {
                cout << "Round " << n << "\n";
                cout << "You lose.\n";
                a = sza;
            } else {
                if (ans == inp.size()) { //A
                    cout << "Round " << n << "\n";
                    cout << "You win.\n";
                    a = sza;
                } else {
                    if (a == (sza - 1) && ans < inp.size()) {
                        cout << "Round " << n << "\n";
                        cout << "You chickened out.\n";
                    }
                }
            }
        }
        cin >> n;
    }
}

/*
Note for myself :

input:
1
abc
abcqwertyu

output:
Round 1
You win.

Still win because we won before making 7 wrong guesses

*/