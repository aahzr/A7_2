#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Barang {
	string nama;
	int jumlah;
	double harga;
};

void tampilkanDaftar(Barang daftar[], int n) {
	cout << "\n--- Daftar Belanja ---\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << daftar[i].nama
		<< " | Jumlah: " << daftar[i].jumlah
		<< " | Harga: " << daftar[i].harga << endl;
	}
}

int tambahBarang(Barang daftar[], int n) {
	cout << "Masukkan nama barang: ";
	cin.ignore();
	getline(cin, daftar[n].nama);
	cout << "Masukkan jumlah: ";
	cin >> daftar[n].jumlah;
	cout << "Masukkan harga: ";
	cin >> daftar[n].harga;
	return n + 1;
}

int hapusBarang(Barang daftar[], int n) {
	int indeks;
	cout << "Masukkan nomor barang yang ingin dihapus: ";
	cin >> indeks;
	if (indeks < 1 || indeks > n) {
		cout << "Nomor barang tidak valid!\n";
	return n;
	}
	for (int i = indeks - 1; i < n - 1; i++) {
		daftar[i] = daftar[i + 1];
	}
	cout << "Barang berhasil dihapus!\n";
	return n - 1;
}

double hitungTotal(Barang daftar[], int n, double pajak = 0.1, double diskon = 0.05) {
	double total = 0;
	for (int i = 0; i < n; i++) {
	total += daftar[i].harga * daftar[i].jumlah;
	}
	total += total * pajak;
	total -= total * diskon;
	return total;
}

void simpanKeFile(Barang daftar[], int n, double anggaran) {
	ofstream file("belanja.txt");
	if (!file) {
	cout << "Gagal membuka file untuk menyimpan data.\n";
	return;
	}
	file << anggaran << endl;

	for (int i = 0; i < n; i++) {
		file << daftar[i].nama << " " << daftar[i].jumlah << " " << daftar[i].harga << endl;
	}
	file.close();
	cout << "Data berhasil disimpan ke file.\n";
}

int pulihkanDariFile(Barang daftar[], double &anggaran) {
	ifstream file("belanja.txt");
	if (!file) {
	cout << "File tidak ditemukan atau kosong.\n";
	return 0;
	}
	file >> anggaran;
	int n = 0;
	while (file >> daftar[n].nama >> daftar[n].jumlah >> daftar[n].harga) {
	n++;
	}
	file.close();
	cout << "Data berhasil dipulihkan dari file.\n";
	return n;
}

void beliSemuaBarang (Barang daftar[], int n, double anggaran){
	string bulan;
	cout << "Belanja bulan berapa ? [bulan1.txt]: ";
	cin >> bulan;
	ofstream file(bulan);
	if (!file) {
	cout << "Gagal membuka file untuk menyimpan data pembelian.\n";
	return;
	}
	file << anggaran << endl;

	for (int i = 0; i < n; i++) {
		file << daftar[i].nama << " " << daftar[i].jumlah << " " << daftar[i].harga << endl;
	}
	file.close();
	cout << "Riwayat pembelian berhasil disimpan.\n";
}

int main() {
	Barang daftar[100];
	int n = 0;
	double anggaran = 0.0;

int pilihan;
	do {
		cout << "\n============================\n";
		cout << "|   Menu Belanja Bulanan   |\n";
		cout << "|        Kelompok 2        |";
		cout << "\n============================\n";
		cout << "|Anggaran saat ini: " << fixed << setprecision(2) << anggaran << endl;
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
		cin >> pilihan;

	switch (pilihan) {
		case 1:
			n = tambahBarang(daftar, n);
			break;
		case 2:
			n = hapusBarang(daftar, n);
			break;
		case 3:
			tampilkanDaftar(daftar, n);
			break;
		case 4: {
			double total = hitungTotal(daftar, n);
			cout << "Total Biaya (termasuk pajak dan diskon): " << fixed << setprecision(2) << total <<
			endl;
			if (total > anggaran) {
				cout << "Peringatan: Total melebihi anggaran!\n";
			}
			break;
		}
		case 5:
			cout << "Masukkan anggaran baru: ";
			cin >> anggaran;
			cout << "Anggaran berhasil diperbarui!\n";
			break;
		case 6:
			simpanKeFile(daftar, n, anggaran);
			break;
		case 7:
			n = pulihkanDariFile(daftar, anggaran);
			break;
		case 8:
			beliSemuaBarang (daftar, n, anggaran)
		case 8:
			cout << "Terima kasih telah menggunakan program belanja bulanan.\n";
			break;
		default:
			cout << "Pilihan tidak valid.\n";
	}
	} while (pilihan != 8);

	return 0;
}