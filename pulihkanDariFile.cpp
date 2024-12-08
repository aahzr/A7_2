#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

int pulihkanDariFile(Barang daftar[], double &anggaran) {
    ifstream file("list_belanja.txt");
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

void tampilkanDaftar(Barang daftar[], int n) {
    cout << "\n--- Daftar Belanja ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << daftar[i].nama 
             << " | Jumlah: " << daftar[i].jumlah 
             << " | Harga: " << daftar[i].harga << endl;
    }
}

int main() {
    Barang daftar[100];
    int n = 0;
    double anggaran = 0;

    n = pulihkanDariFile(daftar, anggaran);

    tampilkanDaftar(daftar, n);
}