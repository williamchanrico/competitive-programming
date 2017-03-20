#include <stdio.h>

int main(){
	int SizeMatrik11, SizeMatrik12,
		SizeMatrik21, SizeMatrik22;
		
	// Input Ukuran dan Isi Matrik1
	scanf("%d %d", &SizeMatrik11,&SizeMatrik12);
	int Matrik1[SizeMatrik11][SizeMatrik12];

	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			scanf("%d", &Matrik1[a][b]);
		}
	}
	// Input Ukuran dan Isi Matrik2
	scanf("%d %d", &SizeMatrik21, &SizeMatrik22);
	int Matrik2[SizeMatrik21][SizeMatrik22];

	for(int a=0;a<SizeMatrik21;a++){
		for(int b=0;b<SizeMatrik22;b++){
			scanf("%d", &Matrik2[a][b]);
		}
	}
	
	// Cek kesamaan Matrik1 dengan Matrik2 sebelum diputar
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik21;b++){
			if(a==(SizeMatrik11-1) && b==(SizeMatrik21-1) && Matrik1[a][b]==Matrik2[a][b]){
				printf("0\n");
				return 0;
			}
			if(Matrik1[a][b]!=Matrik2[a][b]){
				a=SizeMatrik11;
				b=SizeMatrik12;
			}
		}
	}
					
	// Deklarasi array baru untuk menampung hasil perputaran Matrik1
	int Matrik3[SizeMatrik11][SizeMatrik12];

	// Putar Matrik1 90 derajat dan Simpan di Matrik3
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			Matrik3[a][b]=Matrik1[(SizeMatrik12-1)-b][a];
		}
	}
		
	// Cek kesamaan Matrik1 yang sudah diputar 90 derajat(Matrik3) dengan Matrik2
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			if(Matrik3[a][b]==Matrik2[a][b] && a==(SizeMatrik11-1) && b==(SizeMatrik12-1)){
				printf("90\n");
				return 0;
			}	else{
					if(Matrik3[a][b]!=Matrik2[a][b]){
						a=SizeMatrik11;
						b=SizeMatrik12;
					}
				}
		}
	}


	// Timpa nilai dari Matrik1 dengan nilai Matrik1-yang-telah-diputar di Matrik3
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			Matrik1[a][b]=Matrik3[a][b];
		}
	}
		
	// Putar Matrik1 dengan besar 90 derajat lagi hingga total 180 derajat dari nilai awal Matrik1 
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			Matrik3[a][b]=Matrik1[(SizeMatrik12-1)-b][a];
		}
	}
		
	// Cek kesamaan Matrik3 yang berisi nilai hasil-Matrik1-setelah-diputar-180-derajat dengan Matrik2
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			if(Matrik3[a][b]==Matrik2[a][b] && a==(SizeMatrik11-1) && b==(SizeMatrik12-1)){
				printf("180\n");
				return 0;
			}	else{
					if(Matrik3[a][b]!=Matrik2[a][b]){
						a=SizeMatrik11;
						b=SizeMatrik12;
					}
				}
		}
	}

	

	// Timpa nilai dari Matrik1 dengan nilai Matrik1-yang-telah-diputar di Matrik3
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			Matrik1[a][b]=Matrik3[a][b];
		}
	}
		
	// Putar Matrik1 dengan besar 90 derajat lagi hingga total 270 derajat dari nilai awal Matrik1 
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			Matrik3[a][b]=Matrik1[(SizeMatrik12-1)-b][a];
		}
	}
		
	// Cek kesamaan Matrik3 yang berisi nilai hasil-Matrik1-setelah-diputar-270-derajat dengan Matrik2
	for(int a=0;a<SizeMatrik11;a++){
		for(int b=0;b<SizeMatrik12;b++){
			if(Matrik3[a][b]==Matrik2[a][b] && a==(SizeMatrik11-1) && b==(SizeMatrik12-1)){
				printf("270\n");
				return 0;
			}	else{
					if(Matrik3[a][b]!=Matrik2[a][b]){
						a=SizeMatrik11;
						b=SizeMatrik12;
						printf("tidak sama\n");
					}
				}
		}
	}
	

}
