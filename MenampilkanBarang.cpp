#include <iostream>
using namespace std;

// Definisikan struktur Barang
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

int main() {
    // Buat array barang dan inisialisasi
    Barang daftarBarang[3] = {
        {"Apel", 10, 15000.0},
        {"Pisang", 5, 12000.0},
        {"Jeruk", 8, 14000.0}
    };

    // Menampilkan daftar barang
    tampilkanDaftar(daftarBarang, 3);

    return 0;
}
