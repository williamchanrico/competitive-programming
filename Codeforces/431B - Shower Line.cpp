#include <algorithm>
#include <iostream>
using namespace std;

long long ans = -1, temp;
int data[10][10], stud[5] = { 1, 2, 3, 4, 5 };

int main()
{
    for (int a = 1; a <= 5; a++)
        for (int b = 1; b <= 5; b++)
            cin >> data[a][b];
    for (int brute = 0; brute < 120; brute++) {
        for (int counter = 0; counter < 5; counter++)
            for (int a = counter; a < 4; a += 2)
                temp += data[stud[a]][stud[a + 1]] + data[stud[a + 1]][stud[a]];
        ans = max(ans, temp);
        temp = 0;
        next_permutation(stud, stud + 5);
    }
    cout << ans << "\n";
}
