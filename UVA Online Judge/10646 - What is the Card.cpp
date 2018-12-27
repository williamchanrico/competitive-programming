#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

string inp;
vector<string> cards;

int main()
{
    int T, Y, pos, n = 1;
    cin >> T;
    while (T--) {
        Y = 0;
        pos = 26;
        for (int a = 0; a < 52; a++) {
            cin >> inp;
            cards.push_back(inp);
        }
        for (int a = 0; a < 3; a++) {
            if (cards[pos][0] == 'A' || cards[pos][0] == 'K' || cards[pos][0] == 'Q' || cards[pos][0] == 'J' || cards[pos][0] == 'T') {
                Y += 10;
                cards.erase(cards.begin() + pos);
                pos--;
            } else {
                int temp = atoi(cards[pos].c_str());
                Y += temp;
                for (int b = pos; b >= (pos - (10 - temp)); b--)
                    cards.erase(cards.begin() + b);
                pos -= (10 - temp) + 1;
            }
        }
        cout << "Case " << n << ": " << cards[Y - 1] << "\n";
        n++;
        cards.clear();
    }
}