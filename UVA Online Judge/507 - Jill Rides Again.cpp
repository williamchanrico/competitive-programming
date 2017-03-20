#include <stdio.h>

#define INF 1000000000

int T, N, inp;

int main(){
	scanf("%d", &T);
	for(int a=1;a<=T;a++){
		int maks=-INF, start=1, end=1, temp=1, sum=0;
		scanf("%d", &N);
		for(int b=1;b<=N-1;b++){
			scanf("%d", &inp);
			sum+=inp;
			if(sum<0){
				sum=0;
				temp=b+1;
			}else{ 
				if(maks<sum){
					maks=sum;
					start=temp;
					end=b+1;
				}else if(maks==sum){
					if(b+1-temp>end-start){ end=b+1; start=temp; }
				}
			}
		}
		if(maks>-1){
			printf("The nicest part of route %d is between stops %d and %d\n", a, start, end);
		}else{
			printf("Route %d has no nice parts\n", a);
		}
	}
}