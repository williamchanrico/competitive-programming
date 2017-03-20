#include <bits/stdc++.h>
using namespace std;
 
int Q, N, jenis[100005];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int temp;
    cin >> N;
    for(int a=0;a<N;a++){
        cin >> temp;
        if(a==0) jenis[a]=temp;
        else jenis[a]=temp+jenis[a-1];
    }
    cin >> Q;
    while(Q--){
        cin >> temp;
        int up=N;
        int down=0;
        while(down<up){
            int mid=(up+down)/2;
            if(temp<jenis[mid]){
                up=mid;
            }else if(temp>jenis[mid]){
                down=mid+1;
            }else{
                up=mid; down=mid;
            }
        }
        cout << up+1 << "\n";
    }
}