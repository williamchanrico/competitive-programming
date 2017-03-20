#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int n, temp;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &temp);
		pq.push(temp);
	}
	int timeleft=710, ans1=0, ans2=0;
	while(timeleft>0 && !pq.empty()){
		timeleft-=pq.top();
		if(timeleft>=360){
			ans1++; pq.pop();
		}else if(timeleft>=0){
			ans2+=(360-timeleft);
			ans1++; pq.pop();
		}
	}
	printf("%d %d\n", ans1, ans2);
}