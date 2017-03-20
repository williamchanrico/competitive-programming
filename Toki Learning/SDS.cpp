#include <stdio.h>
#include <math.h>

int main(){
	int T;
	double data[10010], sum=0, average, temp, max=-1000010, min=10000000;
	scanf("%d", &T);
	for(int a=0;a<T;a++){
		scanf("%lf", &data[a]);
		sum+=data[a];
		if(max<data[a])
			max=data[a];
		if(min>data[a])
			min=data[a];
	}
	
	printf("%.2lf %.2lf %.2lf ", min, max, sum/T);
	average=sum/T;
	sum=0;
	for(int a=0;a<T;a++){
		sum+=pow((data[a]-average), 2);
	}
	sum/=(T-1);
	printf("%.2lf\n", sqrt(sum));
}