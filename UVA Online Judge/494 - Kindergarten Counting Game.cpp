#include <bits/stdc++.h>
using namespace std;

int count(string x)
{
    int ans = 0;
    bool valid = false;

    for_each(x.begin(), x.end(), [&](char x) {
        if (isalpha(x)) {
            valid = true;
        } else if (valid) {
            ++ans;
            valid = false;
        }
    });

    return (valid ? ans + 1 : ans);
}

/*

int count(string input){
	int ans = 0;

	input += " ";

	for_each(input.begin(), input.end(), [](char &x){ x = (!isalpha(x) ? ' ' : x); });

	for(auto a = input.begin(); a != input.end(); a++){
		auto *pA = &(*a);
		
		if(isalpha(*a) && *(pA + 1) == ' ')
			++ans;
	}
	
	return ans;
}

*/

int main()
{
    string input;

    while (getline(cin, input)) {
        cout << count(input) << "\n";
    }
}