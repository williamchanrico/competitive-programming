#include <stdio.h>
#include <queue>
using namespace std;

queue<int> q;
int N, M, counter=0;
long long maks, ans=0, temp;

int main(){
	bool pertamax=true;
	scanf("%d %d", &N, &M);
	for(int a=0;a<N;a++){
		scanf("%lld", &temp);
		q.push(temp);
		ans+=(long long)temp; 
		counter++;
		if(counter==M){
			counter--;
			if(pertamax)
				maks=ans;
			pertamax=false;
			//printf("kondisi ans=%lld maks=%lld dan kondisi ans<maks=%d\n", ans, maks, ans>maks);
			if(ans>maks)
				maks=ans;
			ans-=q.front(); q.pop();
		}
	}
	printf("%lld\n", maks);
}
