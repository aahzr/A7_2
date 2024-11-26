#include <iostream>
#include <string>

using namespace std;

struct Barang {
    string nama;
    double harga;
    int jumlah;
};

double hitungTotal(Barang daftar[], int n, double pajak = 0.1, double diskon = 0.05) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += daftar[i].harga * daftar[i].jumlah;
    }
    total += total * pajak;
    total -= total * diskon; 
    return total;
}

int main() {
    Barang daftar[3] = {
        {"Buku", 20000, 2},
        {"Pensil", 5000, 5},
        {"Penghapus", 3000, 3}
    };
    int n = 3;
    double totalHarga = hitungTotal(daftar, n);

    cout << "Total harga setelah pajak dan diskon: Rp" << totalHarga << endl;

    return 0;
}