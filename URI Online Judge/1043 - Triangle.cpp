#include <bits/stdc++.h>
using namespace std;

int main(){
	double line[3];
	for(int a=0;a<3;a++)
		scanf("%lf", &line[a]);
	sort(line, line+3);
	if(line[0]+line[1]>line[2]) printf("Perimetro = %.1lf\n", line[0]+line[1]+line[2]);
	else printf("Area = %.1lf\n", (line[1]+line[2])*line[0]/2);
}