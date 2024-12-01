#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

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

int main() {
    int n = 3;
    double anggaran = 2000000;

    Barang daftarBarang[3] = {
    {"Apel", 10, 15000.0},
    {"Pisang", 5, 12000.0},
    {"Jeruk", 8, 14000.0}
    };

    simpanKeFile(daftarBarang, n, anggaran);
}