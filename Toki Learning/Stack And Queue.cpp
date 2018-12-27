#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<int> l;
    string h;
    int n, t;

    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> h;
        if (h == "pop_front") {
            l.pop_front();
        } else if (h == "pop_back") {
            l.pop_back();
        } else if (h == "push_back") {
            cin >> t;
            l.push_back(t);
        } else if (h == "push_front") {
            cin >> t;
            l.push_front(t);
        }
    }
    for (list<int>::iterator a = l.begin(); a != l.end(); a++)
        cout << *a << endl;
}