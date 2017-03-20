#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;

int main(){
	int n, ans=0;
	cin >> n;
	while(n!=0){
		long long temp;
		cin >> temp;
		pq.push(temp);
		for(int a=1;a<n;a++){
			cin >> temp;
			pq.push(temp);
		}
		temp=pq.top();
		pq.pop();
		for(int a=1;a<n;a++){
			temp+=pq.top();
			pq.pop();
			ans+=temp;
			pq.push(temp);
			temp=pq.top();
			pq.pop();
		}
		cout << ans << "\n";
		ans=0;
		cin >> n;
	}
}