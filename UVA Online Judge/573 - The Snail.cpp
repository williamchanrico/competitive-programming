#include <stdio.h>

int main(){
	double H, C, S, F;
	scanf("%lf%lf%lf%lf", &H, &C, &S, &F);
	while(H!=0){
		double minus=(F/100)*C;
		int day=1;
		double climbed=0;
		while(climbed<=H && climbed>=0){
			climbed+=C;
			if(C-minus>0)C-=minus; else C=0;
			if(climbed>H){
				printf("success on day %d\n", day);
			}else{
				climbed-=S;
				if(climbed<0)
					printf("failure on day %d\n", day);
			}
			day++;
		}
		scanf("%lf%lf%lf%lf", &H, &C, &S, &F);
	}
}