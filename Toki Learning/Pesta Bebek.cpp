#include <iostream>
using namespace std;

string data[1005];
int jmlData;

int main()
{
    cin >> jmlData;
    cin.ignore();
    for (int a = 0; a < jmlData; a++) {
        getline(cin, data[a]);
        for (int b = 0, len = data[a].length(); b < len; b++)
            data[a][b] = tolower(data[a][b]);
        int temp = 1;
        for (int b = 0; b < a; b++)
            if (data[a] >= data[b])
                temp++;
        cout << temp << endl;
    }
}

/*
Pesta Bebek

Batas Waktu	 1 detik
Batas Memori	 16 MB
Pak Dengklek tahun ini terpilih menjadi tuan rumah Pesta Bebek. Pesta tersebut akan dihadiri oleh semua pemilik bebek ternama di Indonesia. Pada acara tersebut, setiap tamu yang baru hadir akan diberikan sebuah nomor (yang kemudian mungkin akan dijadikan nomor undian) yang merupakan posisi namanya di daftar tamu yang sudah hadir. Daftar tersebut diurutkan berdasarkan urutan kamus tanpa membedakan huruf besar dan huruf kecil.

Jadi, sederhananya, setiap kali ada tamu yang baru hadir, nama tamu yang sudah hadir termasuk yang baru hadir akan diurutkan, dan tamu yang baru hadir tersebut akan mendapatkan nomor sesuai posisi namanya di urutan tamu yang sudah hadir.

Diberikan daftar urutan hadir N (1 ≤ N ≤ 1.000) orang tamu Pesta Bebek, tentukanlah nomor yang didapatkan setiap tamu.

Format Masukan

Baris pertama berisi sebuah bilangan bulat N. N baris berikutnya berisi masing-masing nama tamu sesuai dengan urutan hadirnya, yaitu pada saat tamu ke-i hadir, tamu ke-1 sampai ke-(i-1) tentunya sudah hadir, dan tamu ke-(i+1) sampai ke-N tentunya belum hadir. Tidak ada dua tamu yang hadir secara bersamaan dan tidak ada dua tamu yang memiliki nama sama persis. Nama tersebut hanya akan berisi antara 1 sampai 20 karakter 'a' - 'z', 'A' - 'Z', dan spasi. Pada kamus, spasi muncul terlebih dahulu dibanding semua karakter alfabet.

Format Keluaran

N buah baris masing-masing berisi sebuah bilangan bulat yang merupakan nomor tamu yang datang pada urutan tersebut.

Contoh Masukan

5
BUDI
ANI R
ANISA
ANDI
TARZAN
Contoh Keluaran

1
1
2
1
5
Contoh Masukan

3
ANDI
BUDI
TARZAN
Contoh Keluaran

1
2
3
Penjelasan

Pada contoh pertama, saat BUDI datang, dia hanya sendirian, tentunya dia mendapatkan nomor 1. Saat ANI R datang, menurut urutan kamus ia muncul terlebih dahulu sebelum BUDI, sehingga ANI R mendapatkan nomor 1. Saat ANISA datang, menurut urutan kamus ia muncul terlebih dahulu sebelum BUDI tapi muncul setelah ANI R, sehingga ANISA mendapat nomor 2. Begitu selanjutnya sampai TARZAN mendapatkan nomor 5.
*/