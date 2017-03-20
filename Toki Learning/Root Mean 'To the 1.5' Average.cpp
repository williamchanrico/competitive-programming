#include <bits/stdc++.h>
using namespace std;
 
double data[50005];
int N;
 
double f(double x){
    double jmlh=0;
    for(int a=0;a<N;a++){
        double temp = fabs(data[a]-x);
        temp = temp * temp * temp;
        temp = sqrt(temp);
        jmlh+=temp;
    }
    return jmlh;
}
 
int main(){
    scanf("%d", &N);
    for(int a=0;a<N;a++){
        scanf("%lf", &data[a]);
    }
    double up=1000.00, down=-1000.00;
    while(fabs(up-down)>0.0001){
        double mid=(up+down)/2;
        if(f(up)<f(down))
            down=mid;
        else up=mid;
    }
    printf("%.2lf\n", (up+down)/2);
}