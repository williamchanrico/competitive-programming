#include <bits/stdc++.h>
using namespace std;

int main(){
	double H, U, D, F;

	while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H != 0){
		double climbed = 0, minus = F / 100.0 * U;

		for(int day = 1; day; day++){
			climbed += (U > 0 ? U : 0);

			if(climbed > H){
				printf("success on day %d\n", day);

				break;
			}

			climbed -= D;
			U -= minus;
			
			if(climbed < 0){
				printf("failure on day %d\n", day);

				break;
			}
		}
	}
}
