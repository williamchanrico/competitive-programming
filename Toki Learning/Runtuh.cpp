#include <iostream>
#include <string>
using namespace std;
   
int x,y, tab[25][15], mulai=1;
   
bool f(int baris){
    for(int a=0;a<y;a++)
        if(tab[baris][a]!=1)
            return false;
    return true;
}
   
void hajar(int baris){
    for(int a=0;a<y;a++)
        tab[baris][a]=0;
}
   
bool way(int bawah, int atas, int kolom){
    for(int a=bawah-1;a>atas;a--)
        if(tab[a][kolom]!=0)
            return false;
    return true;
}
   
void runtuh(int baris){
    for(int a=0;a<y;a++)
        if(tab[baris][a]==1)
            for(int b=x-1;b>baris;b--)
                if(tab[b][a]==0 && way(b, baris, a)){
                    tab[b][a]=1;
                    tab[baris][a]=0;
                    break;
                }
}
  
void inputdata(){
    string temp[x];
    for(int a=0;a<x;a++)
            cin >> temp[a];
    for(int a=0;a<x;a++)
        for(int b=0;b<y;b++)
            tab[a][b]=((temp[a][b]==48)?0:1);
}
  
int main(){
    bool again=true;
     
    cin >> x >> y;
    inputdata();
    while(again){
        again=false;
        for(int a=0;a<x;a++)
            if(f(a)){
                again=true;
                hajar(a);    
                mulai=a;
            }
        for(int a=mulai-1;a>=0;a--)
            runtuh(a);
    }
    for(int a=0;a<x;a++){
        for(int b=0;b<y;b++)
            cout << tab[a][b];
        cout << endl;
    }
       
   
}