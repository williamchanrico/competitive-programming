#include <stdio.h>

int t, x, y, ex, ye;

int main(){
	scanf("%d", &t);
	
	while(t != 0){
		
		scanf("%d %d", &ex, &ye);
		
		for(int a = 0; a < t; a++){
			
			scanf("%d %d", &x, &y);
			
			if(x == ex || y == ye){
				printf("divisa\n");
			}else{
				if(x > ex && y > ye)
					printf("NE\n");
				else if(x > ex && y < ye)
					printf("SE\n");
				else if(x < ex && y > ye)
					printf("NO\n");
				else
					printf("SO\n");
			}
		}

		scanf("%d", &t);
	}
}