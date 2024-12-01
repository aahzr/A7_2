#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

int main() {
    Barang daftar[100];
    int n = 1;
    double anggaran = 0;

    cout << "Masukkan anggaran baru: ";
    cin >> anggaran;
    cout << "Anggaran berhasil diperbarui!\n";

    return 0;
}