#include <iostream>
#include <queue>
using namespace std;

queue<long long> q;
long long n, k;
long long temp, sum=0, mins=10000000000, ans;
int count=0;

int main(){
	cin >> n >> k;
	for(int a=0;a<n;a++){
		cin >> temp;
		q.push(temp);
		count++;
		sum+=temp;
		if(count==k){
			count-=1;
			if(mins>sum){
				mins=sum;
				ans=a-k+2;
			}
			sum-=q.front(); q.pop();
		}
	}
	cout << ans << "\n";
}