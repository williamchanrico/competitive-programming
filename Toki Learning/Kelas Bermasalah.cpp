#include <stdio.h>
#include <vector>
using namespace std;

vector<double> v;
double Jml=0, temp;

int main(){
	int T, n;
	
	scanf("%d", &T);
	while(T>0){
		scanf("%d", &n);
		double Jml=0;
		for(int a=0;a<n;a++){
			scanf("%lf", &temp);
			v.push_back(temp);
			Jml+=temp;
		}
		Jml/=n;
		int ans=0;
		for(int a=0;a<n;a++)
			if(v[a]<Jml)
				ans++;
		printf("%d\n", ans);
		v.clear();
		T--;
	}
}

/*

Kelas Bermasalah

Pak Gaus kali ini sedang kesal dengan salah satu kelasnya, karena ternyata banyak muridnya yang tidak mengerjakan PR, bahkan ada yang sering membolos! Oleh karena itu ia ingin mengetahui seberapa banyak muridnya yang bermasalah, dengan hanya menganalisa daftar nilai yang dimilikinya.

Karena kesal, Pak Gaus tidak dapat berhitung dengan benar. Oleh karena itu, ia meminta bantuan anda untuk menghitung berapa murid di kelasnya yang memiliki nilai di bawah rata-rata. Adapun nilai rata-rata di sini dapat anda hitung dengan cara menjumlahkan nilai dari semua murid, kemudian dibagi dengan jumlah murid. Untuk lebih jelasnya, anda dapat memperhatikan contoh berikut ini.

Misalnya terdapat 4 orang murid, dengan nilai 25, 20, 30 dan 90 (terlihat kan, mana murid yang bermasalah dan mana yang tidak...). Rata-rata kelas dapat dihitung dengan mudah, yaitu (25+20+30+90) / 4 = 41,25. Oleh karena itu, dalam kasus ini, terdapat 3 orang murid yang nilainya di bawah rata-rata (yaitu murid yang nilainya 25, 20 dan 30).

Input Format

Input diawali oleh satu baris dengan satu angka, T yang menandakan jumlah kasus (T ≤ 100). Penjelasan tiap kasus menyusul di bawahnya, dengan setiap kasus diwakili oleh dua baris. Baris pertama berisi sebuah angka N, yaitu jumlah murid di kelas (1 ≤ N ≤ 10.000). Baris kedua berisi tepat N buah bilangan, yaitu nilai dari tiap murid. Perhatikan bahwa seperti biasanya, nilai minimal adalah 0 dan maksimal adalah 100.

Output Format

Output harus terdiri dari tepat T baris, di mana tiap baris berisi satu angka, yaitu jumlah anak dengan nilai di bawah rata-rata kelas pada kasus yang dimaksud.

Sample Input

2
4
25 20 30 90
3
45 50 55
Sample Output

3
1

*/