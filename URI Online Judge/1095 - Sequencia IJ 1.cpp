#include <stdio.h>
 
int main(){
    int I=1, J=60;    
    while(J!=-5){
        printf("I=%d J=%d\n", I, J);
        I+=3; J-=5;
    }
}