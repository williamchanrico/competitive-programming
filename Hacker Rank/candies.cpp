#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
    long long ans = 0;

    scanf("%d", &N);

    vector<int> v, vv;
    v.assign(N + 1, 0);
    vv.assign(N + 1, 1);

    scanf("%d", &v[0]);
    for(int a = 1; a < N; a++){
        scanf("%d", &v[a]);

        if(v[a] > v[a - 1]){
            vv[a] = vv[a - 1] + 1;
        }else if(v[a] < v[a - 1] && vv[a] == vv[a - 1]){
            vv[a - 1]++;
        }
    }

    for(int a = N - 2; a >= 0; a--){
        if(v[a] > v[a + 1] && vv[a] <= vv[a + 1]){
            vv[a] = vv[a + 1] + 1;
        }else if(v[a] < v[a + 1] && vv[a] == vv[a + 1]){
            vv[a + 1]++;
        }

        ans += vv[a + 1];
    }
    ans += vv[0];


    printf("%lld\n", ans);
}
