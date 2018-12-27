#include <iostream>

int f(int x)
{
    if (x == 1)
        return 1;
    return (x % 2) ? 1 + f(3 * x + 1) : 1 + f(x / 2);
}

int main()
{
    long long inp1;
    long long inp2;
    long long ans;
    long long temp;

    while (std::cin >> inp1 >> inp2) {
        ans = -1;

        for (int a = (inp2 > inp1 ? inp1 : inp2); a <= (inp2 > inp1 ? inp2 : inp1); a++) {
            temp = f(a);
            ans = (ans < temp) ? temp : ans;
        }
        std::cout << inp1 << " " << inp2 << " " << ans << "\n";
    }
}