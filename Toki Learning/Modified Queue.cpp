#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int Data[10000010];
 
int main(){
 
    int jmlData, x, y;
    int belakang=5000000, depan=5000000;
    string str;
    bool reverse=true;
	
    cin >> jmlData;
    for(int a=0;a<jmlData;a++){
        cin >> str;
		if(reverse){
			if(str=="add" || str=="del"){
				if(str=="add"){
					cin >> x >> y;
					for(int b=0;b<y;b++){
						belakang--;
						Data[belakang]=x;
					}
					cout << depan-belakang << endl;
				}else{
					cin >> x;
					cout << Data[depan-1] << endl;
					depan-=x;
				}
			}else{
				reverse= !(reverse);
				swap(belakang, depan);
			}
		}else{
			
			if(str=="add" || str=="del"){
				if(str=="add"){
					cin >> x >> y;
					for(int b=0;b<y;b++){
						Data[belakang]=x;
						belakang++;
					}
					cout << belakang-depan << endl;
				}else{
					cin >> x;
					cout << Data[depan] << endl;
					depan+=x;
				}
			}else{
				reverse= !(reverse);
				swap(belakang, depan);
			}
			
		}
    }
}