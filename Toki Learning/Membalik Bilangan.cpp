#include <stdio.h>
#include <string.h>
using namespace std;

int inp, temp;

int main(){
	scanf("%d", &inp);
	while(inp--){
		scanf("%d", &temp);
		while(temp%10==0 && temp!=0) temp/=10;
		char ans[100];
		sprintf(ans, "%d", temp);
		for(int a=strlen(ans)-1;a>-1;a--) printf("%c", ans[a]);
		printf("\n");
	}
}
