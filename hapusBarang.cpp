#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

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

int main() {
    Barang daftar[100];
    int n = 1;

    n = hapusBarang(daftar, n);

    return 0;
}