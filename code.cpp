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
	cout << "\n============================\n";
	cout << "|   Menu Belanja Bulanan   |\n";
	cout << "|        Kelompok 2        |";
	cout << "\n============================\n";

	cout << "|Anggaran saat ini: "<< endl;
	cout << "============================\n";
	cout << "|1. Tambah Barang          |" << endl;
	cout << "|2. Hapus Barang           |" << endl;
	cout << "|3. Tampilkan Daftar       |" << endl;
	cout << "|4. Hitung Total Biaya     |" << endl;
	cout << "|5. Ubah Anggaran          |" << endl;
	cout << "|6. Simpan Ke File         |" << endl;
	cout << "|7. Pulihkan Dari File     |" << endl;
	cout << "|8. Keluar                 |" << endl;
	cout << "============================\n";
	cout << "|Pilih menu: ";

return 0;
}