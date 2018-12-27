#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, temp;

int main()
{
    while (cin >> n) {
        bool isQ = true, isPQ = true, isST = true;
        queue<int> q;
        priority_queue<int> pq;
        stack<int> st;

        for (int a = 0; a < n; a++) {
            cin >> temp;
            if (temp == 1) {
                cin >> temp;
                q.push(temp);
                pq.push(temp);
                st.push(temp);
            } else {
                cin >> temp;
                if (temp != (q.empty() ? -1 : q.front()))
                    isQ = false;
                if (temp != (pq.empty() ? -1 : pq.top()))
                    isPQ = false;
                if (temp != (st.empty() ? -1 : st.top()))
                    isST = false;
                if (!q.empty())
                    q.pop();
                if (!pq.empty())
                    pq.pop();
                if (!st.empty())
                    st.pop();
            }
        }
        if (isQ || isPQ || isST) {
            if (isQ && !(isPQ || isST))
                cout << "queue\n";
            else if (isPQ && !(isQ || isST))
                cout << "priority queue\n";
            else if (isST && !(isQ || isPQ))
                cout << "stack\n";
            else
                cout << "not sure\n";
        } else {
            cout << "impossible\n";
        }
    }
}