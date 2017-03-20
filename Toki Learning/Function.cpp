#include <stdio.h>

int Function(int a);

int main(){
	int n,Answer;
	scanf("%d",&n);
	if(n>=0 && n<=10){
		Answer=Function(n);
		printf("%d\n",Answer);
	}	else{
			printf("ditolak\n");
		}
}
	
int Function(int a){
	if(a==0){
		return 1;
	}	else{
			return(a*Function(a-1));
		}
}