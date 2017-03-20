#include <bits/stdc++.h>
using namespace std;

int N, M;
string t[20];

int main(){
	//freopen("o.txt", "w", stdout);
	bool firstline = true;

	cin >> N >> M;

	for(int a = 0; a <= 15; a++)
		for(int b = 0; b <= 15; b++)
			t[a][b] = ' ';

	for(int a = 0; a < N; a++)
		cin >> t[a];

	cout << "***\n";

	for(int a = 0; a < N; a++){
		for(int b = 1; b < 3; b++){
			if(firstline){
				b--;
				firstline = false;
			}

			switch(b){
			case 0:
				for(int c = 0; c < M; c++){
					bool masihada = false;

					for(int d = c + 1; d < M; d++)
						if(t[a][d] == '0')
							masihada = true;

					if(t[a][c] == '0' && masihada)
						cout << " _ ";
					else if(t[a][c] == '0')
						cout << " _";
					else if(masihada)
						cout << "   ";
				}

				break;
			case 1:
				for(int c = 0; c < M; c++){
					if(t[a][c] == '0')
						cout << "/ \\";
					else
						cout << "___";
				}

				break;
			case 2:
				for(int c = 0; c < M; c++){
					bool masihada = false, masihadabawah = false;

					for(int d = c + 1; d < M; d++)
						if(t[a + 1][d] == '0')
							masihadabawah = true;

					for(int d = c + 1; d < M; d++)
						if(t[a][d] == '0')
							masihada = true;

					if(t[a][c] == '0')
						cout << "\\_/";
					else if(t[a + 1][c] == '0' && (masihada || masihadabawah))
						cout << " _ ";
					else if(t[a + 1][c] == '0')
						cout << " _";
					else if(masihada || masihadabawah)
						cout << "   ";
				}

				break;
			}

			cout << "\n";
		}
	}

	cout << "***\n";
}