#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
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

void checkout(Barang daftar[], int &n, double &anggaran, string &bulan) {
    double total = hitungTotal(daftar, n);
    if (total > anggaran) {
        cout << "Total belanja melebihi anggaran sebesar: " 
             << fixed << setprecision(2) << (total - anggaran) << endl;
        return;
    }

    string filename = "Belanja_Bulan_" + bulan + ".txt";
    ofstream file(filename);
    if (!file) {
        cout << "Gagal membuka file untuk menyimpan data pembelian.\n";
        return;
    }
    file << "Anggaran: " << anggaran << "\nBulan: " << bulan << endl;
    for (int i = 0; i < n; i++) {
        file << daftar[i].nama << " " << daftar[i].jumlah << " " << daftar[i].harga << endl;
    }
    file.close();

    cout << "Checkout berhasil! Data disimpan ke file " << filename << endl;

    n = 0;
    anggaran = 0.0;
    bulan = "Default";
}

int main() {
    int n = 3;
    double anggaran = 2000000.0;
    string bulan = "November";
    
    Barang daftar[3] = {
        {"Apel", 10, 15000.0},
        {"Pisang", 5, 12000.0},
        {"Jeruk", 8, 14000.0}
    };

    checkout(daftar, n, anggaran, bulan);

    return 0;
}