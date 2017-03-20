#include <iostream>
using namespace std;

int main(){
	string pos="+x", inp;
	int T;
	cin >> T;
	while(T!=0){
		T--;
		while(T--){
			cin >> inp;
			if(pos=="+x"){
				if(inp=="+y"){
					pos="+y";
				}else if(inp=="-y"){
					pos="-y";
				}else if(inp=="+z"){
					pos="+z";
				}else if(inp=="-z"){
					pos="-z";
				}
			}else if(pos=="-x"){
				if(inp=="+y"){
					pos="-y";
				}else if(inp=="-y"){
					pos="+y";
				}else if(inp=="+z"){
					pos="-z";
				}else if(inp=="-z"){
					pos="+z";
				}
			}else if(pos=="+y"){
				if(inp=="+y"){
					pos="-x";
				}else if(inp=="-y"){
					pos="+x";
				}else if(inp=="+z"){
					pos="+y";
				}else if(inp=="-z"){
					pos="+y";
				}
			}else if(pos=="-y"){
				if(inp=="+y"){
					pos="+x";
				}else if(inp=="-y"){
					pos="-x";
				}else if(inp=="+z"){
					pos="-y";
				}else if(inp=="-z"){
					pos="-y";
				}	
			}else if(pos=="+z"){
				if(inp=="+y"){
					pos="+z";
				}else if(inp=="-y"){
					pos="+z";
				}else if(inp=="+z"){
					pos="-x";
				}else if(inp=="-z"){
					pos="+x";
				}
			}else if(pos=="-z"){
				if(inp=="+y"){
					pos="-z";
				}else if(inp=="-y"){
					pos="-z";
				}else if(inp=="+z"){
					pos="+x";
				}else if(inp=="-z"){
					pos="-x";
				}
			}
		}
		cout << pos << "\n";
		pos="+x";
		cin >> T;
	}
}