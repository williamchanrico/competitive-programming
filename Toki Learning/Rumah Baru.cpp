#include <stdio.h>
#include <utility>
#include <map>
using namespace std;
 
map< pair<int, int>, int > m;
int n, x[105], y, ans=0;
 
bool cari(int x, int y){
    if(x==100 || x==-100 || y==100 || y==-100) return false;
    int a=x-1, b=y;
    bool found=false;
    while(a>=-100){
        if(m.count(make_pair(a, b))==1){ found=true; a=-101; }
        if(!found && a==-100) return false;
        a--;
    }
    found=false; a=x+1;
    while(a<=100){
        if(m.count(make_pair(a, b))==1){ found=true; a=101; }
        if(!found && a==100) return false;
        a++;
    }
    found=false; a=x; b=y-1;
    while(b>=-100){
        if(m.count(make_pair(a, b))==1){ found=true; b=-101; }
        if(!found && b==-100) return false;
        b--;
    }
    found=false; b=y+1;
    while(b<=100){
        if(m.count(make_pair(a, b))==1){ found=true; b=101; }
        if(!found && b==100) return false;
        b++;
    }
    return true;
}
 
int main(){
    scanf("%d", &n);
    for(int a=0;a<n;a++)
        scanf("%d", &x[a]);
    for(int a=0;a<n;a++){
        scanf("%d", &y);
        m[make_pair(x[a], y)]=1;
    }
    for(int a=-100;a<=100;a++)
        for(int b=-100;b<=100;b++)
                if(cari(a, b)) ans++;
    printf("%d\n", ans);
    /* for(map< pair<int, int>, int >::iterator it=m.begin();it!=m.end();it++)
        printf("%d %d = %d\n", it->first.first, it->first.second, it->second);  */
     
}