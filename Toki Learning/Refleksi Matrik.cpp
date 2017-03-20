#include <stdio.h>

int main(){
	int mat1[100][100], mat2[100][100];
	int n, x=0, y=0;
	scanf("%d%d", &n, &n);
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			scanf("%d", &mat1[a][b]);
	scanf("%d%d", &n, &n);
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			scanf("%d", &mat2[a][b]);
	bool identik=true, vertikal=true, horisontal=true, diagonal_kanan_bawah=true, diagonal_kiri_bawah=true;
	for(int a=n-1;a>-1;a--){
		for(int b=0;b<n;b++){
			if(mat1[a][b]!=mat2[x][y]){
				horisontal=false;
				a=-1;
				b=n;
			}
			y++;
			if(y==n){
				x++; y=0;
			}
		}
	}
	x=0; y=0;
	for(int a=0;a<n;a++)
		for(int b=n-1;b>-1;b--){
			if(mat1[a][b]!=mat2[x][y]){
				vertikal=false;
				a=n;
				b=-1;
			}
			y++;
			if(y==n){
				x++; y=0;
			}	
		}
	x=0; y=0;
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++){
			if(mat1[b][a]!=mat2[x][y]){
				diagonal_kanan_bawah=false;
				a=n;
				b=n;
			}
			y++;
			if(y==n){
				x++; y=0;
			}	
		}
	x=0; y=0;
	for(int a=n-1;a>-1;a--)
		for(int b=n-1;b>-1;b--){
			if(mat1[b][a]!=mat2[x][y]){
				diagonal_kiri_bawah=false;
				a=-1;
				b=-1;
			}
			y++;
			if(y==n){
				x++; y=0;
			}	
		}
	x=0; y=0;
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++){
			if(mat1[a][b]!=mat2[x][y]){
				identik=false;
				a=n;
				b=n;
			}
			y++;
			if(y==n){
				x++;
				y=0;
			}
		}
	if(identik)
		printf("identik\n");
	else if(horisontal)
		printf("horisontal\n");
	else if(vertikal)
		printf("vertikal\n");
	else if(diagonal_kanan_bawah)
		printf("diagonal kanan bawah\n");
	else if(diagonal_kiri_bawah)
		printf("diagonal kiri bawah\n");
	else
		printf("tidak identik\n");
}