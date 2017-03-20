#include <stdio.h>

int A, B;
char op;

int main(){
	scanf("%d %c %d", &A, &op, &B);
	switch(op){
		case '+' : printf("%d\n", A+B); break;
		case '-' : printf("%d\n", A-B); break;
		case '*' : printf("%d\n", A*B); break;
		case '>' : printf("%s\n", (A>B)?"benar":"salah"); break;
		case '<' : printf("%s\n", (A<B)?"benar":"salah"); break;
		case '=' : printf("%s\n", (A==B)?"benar":"salah"); break;
	}
}
