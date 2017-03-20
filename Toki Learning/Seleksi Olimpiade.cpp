#include <iostream>
#include <algorithm>

std::string nama[85], kandidat;
int n1[85], n2[85], n3[85], T, jmlPeserta, jmlLolos;

void tukar(int x, int y){
	std::swap(nama[x], nama[y]);
	std::swap(n1[x], n1[y]);
	std::swap(n2[x], n2[y]);
	std::swap(n3[x], n3[y]);
}

bool besarkiri(int x, int y){
	if(n3[x]>=n3[y]){
		if(n3[x]!=n3[y]){
			return true;
		}else{
			if(n2[x]>=n2[y]){
				if(n2[x]!=n2[y]){
					return true;
				}else{
					if(n1[x]>=n1[y]){
						if(n1[x]!=n1[y])
							return true;
					}else{
						return false;
					}
				}
			}else{
				return false;
			}
		}
	}else{
		return false;
	}
}

int main(){
	bool answered=false;
	std::cin >> T;
	while(T>0){
		std::cin >> jmlPeserta >> jmlLolos;
		std::cin >> kandidat;
		for(int a=0;a<jmlPeserta;a++)
			std::cin >> nama[a] >> n1[a] >> n2[a] >> n3[a];
		for(int a=0;a<jmlPeserta;a++)
			for(int b=a+1;b<jmlPeserta;b++)
				if(besarkiri(b, a))
					tukar(a, b);
		for(int a=0;a<jmlLolos;a++)
			if(nama[a]==kandidat){
				std::cout << "YA\n";
				answered=true;
			}
		if(!answered)
			std::cout << "TIDAK\n";
		answered=false;
		
		/*
		for(int a=0;a<jmlPeserta;a++)
			std::cout << nama[a] << " " << n1[a] << " " << n2[a] << " " << n3[a] << std::endl;
		*/
		T--;
	}
	return 0;
}