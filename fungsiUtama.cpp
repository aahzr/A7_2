#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct daftar {
	string nama;
	int jumlah;
	double harga;
};

int main () {
	double anggaran = 2000000;
	string bulan = "November";

	cout << "\n============================\n";
    cout << "|      Belanja Bulanan     |\n";
    cout << "|        Kelompok 2        |";
    cout << "\n============================\n";
    cout << "| Anggaran saat ini: " << fixed << setprecision(2) << anggaran << endl;
    cout << "| Bulan: " << bulan << endl;
    cout << "============================\n";
    cout << "| 1. Ubah Bulan            |" << endl;
    cout << "| 2. Ubah Anggaran         |" << endl;
    cout << "| 3. Tambah Barang         |" << endl;
    cout << "| 4. Hapus Barang          |" << endl;
    cout << "| 5. Lihat Daftar Barang   |" << endl;
    cout << "| 6. Total Biaya           |" << endl;
    cout << "| 7. Simpan Ke File        |" << endl;
    cout << "| 8. Pulihkan Dari File    |" << endl;
    cout << "| 9. Checkout              |" << endl;
    cout << "| 10. Keluar               |" << endl;
    cout << "============================\n";
    cout << "| Pilih menu: ";
return 0;
}