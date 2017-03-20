#include <stdio.h>
#include <string.h>

char inp[1005];

int main(){
	gets(inp);
	for(int a=strlen(inp)-1;a>-1;a--)
		printf("%c", inp[a]);
	printf("\n");
}
