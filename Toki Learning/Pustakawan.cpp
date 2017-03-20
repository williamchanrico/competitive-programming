#include <stdio.h>
#include <algorithm>

int data[1005], n, ans=0;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", &data[a]);
	for(int a=0;a<n;a++){
		int min=a;
		for(int b=a+1;b<n;b++)
			if(data[min]>data[b])
				min=b;
		if(min!=a){
			std::swap(data[min], data[a]);
			ans++;
		}
	}
	printf("%d\n", ans);
}
