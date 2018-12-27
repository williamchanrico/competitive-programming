#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

vector<int> v;

int dp()
{
    vector<int> memo(100000, INF);

    for (int a = 0; a < v.size(); a++)
        *lower_bound(memo.begin(), memo.end(), v[a]) = v[a];

    return lower_bound(memo.begin(), memo.end(), INF) - memo.begin();
}

int main()
{
    int T = 1;

    while (true) {
        int inp;

        v.clear();

        while (scanf("%d", &inp) && inp != -1) {
            v.push_back(inp);
        }

        if (v.size() == 0)
            return 0;

        reverse(v.begin(), v.end());

        if (T != 1)
            printf("\n");

        printf("Test #%d:\n", T++);
        printf("  maximum possible interceptions: %d\n", dp());
    }
}

/* traditional O(n^2) top-down dp

#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int memo[100000];
vector<int> v;

int dp(int idx){
	if(idx == 0)
		return 1;
	if(memo[idx] != -1)
		return memo[idx];

	int ans = 1;

	for(int a = 0; a < idx; a++)
		if(v[a] >= v[idx])
			ans = max(ans, 1 + dp(a));

	return memo[idx] = ans;
}

int main(){
	int T = 1;

	while(true){
		int inp;

		v.clear();

		while(scanf("%d", &inp) && inp != -1){
			v.push_back(inp);
		}

		if(v.size() == 0)
			return 0;

		int ans = -INF;

		memset(memo, -1, sizeof(memo));

		for(int a = 0; a < v.size(); a++)
			ans = max(ans, dp(a));

		if(T != 1)
			printf("\n");

		printf("Test #%d:\n", T++);
		printf("  maximum possible interceptions: %d\n", ans);
	}

}

*/

/* O(n log n) version with set<int>

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int dp(){
	set<int> st;
	set<int>::iterator it;

	for(int a = 0; a < v.size(); a++){
		st.insert(v[a]);
		it = st.find(v[a]);
		it++;
		if(it != st.end())
			st.erase(it);
	}
	
	return st.size();
}

int main(){
	int T = 1;

	while(true){
		int inp;

		v.clear();

		while(scanf("%d", &inp) && inp != -1){
			v.push_back(inp);
		}

		if(v.size() == 0)
			return 0;

		reverse(v.begin(), v.end());

		if(T != 1)
			printf("\n");

		printf("Test #%d:\n", T++);
		printf("  maximum possible interceptions: %d\n", dp());
	}

}

*/

/* bottom-up version

#include <bits/stdc++.h>
using namespace std;

#define INF 1000111000

int memo[100000];
vector<int> v;

int dp(){
	for(int a = 0; a < v.size(); a++){
		memo[a] = 1;

		for(int b = 0; b < a; b++)
			if(v[a] < v[b])
				memo[a] = max(memo[a], memo[b] + 1);
	}
}

int main(){
	int T = 1;

	while(true){
		int inp;

		v.clear();

		while(scanf("%d", &inp) && inp != -1){
			v.push_back(inp);
		}

		if(v.size() == 0)
			return 0;

		dp();

		int ans = -INF;

		for(int a = 0; a < v.size(); a++)
			ans = max(ans, memo[a]);

		if(T != 1)
			printf("\n");

		printf("Test #%d:\n", T++);
		printf("  maximum possible interceptions: %d\n", ans);
	}

}

*/