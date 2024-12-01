#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

int tambahBarang(Barang daftar[], int n) {
    cout << "Masukkan nama barang: ";
    cin >> daftar[n].nama;
    cout << "Masukkan jumlah: ";
    cin >> daftar[n].jumlah;
    cout << "Masukkan harga: ";
    cin >> daftar[n].harga;
    return n + 1;
}

int main() {
    Barang daftar[100];
    int n = 0;

    n = tambahBarang(daftar, n);

    return 0;
}