#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

void tampilkanDaftar(Barang daftar[], int n, const string &bulan) {
    cout << "\n--- Daftar Belanja Bulanan Bulan " << bulan << " ---\n";
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

void simpanKeFile(Barang daftar[], int n, double anggaran, const string &bulan) {
    ofstream file("list_belanja.txt");
    if (!file) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }
    file << "Anggaran: " << anggaran << "\nBulan: " << bulan << endl;
    for (int i = 0; i < n; i++) {
        file << daftar[i].nama << " " << daftar[i].jumlah << " " << daftar[i].harga << endl;
    }
    file.close();
    cout << "Data berhasil disimpan ke file.\n";
}

int pulihkanDariFile(Barang daftar[], double &anggaran, string &bulan) {
    ifstream file("list_belanja.txt");
    if (!file) {
        cout << "File tidak ditemukan atau kosong.\n";
        return 0;
    }
    file >> anggaran >> ws;
    getline(file, bulan);
    int n = 0;
    while (file >> daftar[n].nama >> daftar[n].jumlah >> daftar[n].harga) {
        n++;
    }
    file.close();
    cout << "Data berhasil dipulihkan dari file.\n";
    return n;
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

    // Reset daftar belanja
    n = 0;
    anggaran = 0.0;
    bulan = "Default";
}

int main() {
    Barang daftar[999];
    int n = 0;
    double anggaran = 0.0;
    string bulan = "Default";

    int pilihan;
    do {
        cout << "\n============================\n";
        cout << "|      Belanja Bulanan     |\n";
        cout << "|        Kelompok 2        |";
        cout << "\n============================\n";
        cout << "| Anggaran saat ini: " << fixed << setprecision(2) << anggaran << endl;
        cout << "| Bulan: " << bulan << endl;
        cout << "============================\n";
        cout << "| 1. Ubah Bulan            |" << endl;
        cout << "| 2. Ubah Anggaran         |" << endl;
        cout << "| 3. Tambah Barang         |" << endl;
        cout << "| 4. Hapus Barang          |" << endl;
        cout << "| 5. Lihat Daftar Barang   |" << endl;
        cout << "| 6. Total Biaya           |" << endl;
        cout << "| 7. Simpan Ke File        |" << endl;
        cout << "| 8. Pulihkan Dari File    |" << endl;
        cout << "| 9. Checkout              |" << endl;
        cout << "| 10. Keluar               |" << endl;
        cout << "============================\n";
        cout << "| Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan Bulan: ";
            cin.ignore();
            getline(cin, bulan);
            cout << "Bulan berhasil diperbarui!\n";
            break;
        case 2:
            cout << "Masukkan Anggaran: ";
            cin >> anggaran;
            cout << "Anggaran berhasil diperbarui!\n";
            break;
        case 3:
            n = tambahBarang(daftar, n);
            break;
        case 4:
            n = hapusBarang(daftar, n);
            break;
        case 5:
            tampilkanDaftar(daftar, n, bulan);
            break;
        case 6: {
            double total = hitungTotal(daftar, n);
            cout << "Total Biaya (termasuk pajak dan diskon): " << fixed << setprecision(2) << total << endl;
            if (total > anggaran) {
                cout << "Peringatan: Total belanja melebihi anggaran sebesar: " 
                     << fixed << setprecision(2) << (total - anggaran) << endl;
            }
            break;
        }
        case 7:
            simpanKeFile(daftar, n, anggaran, bulan);
            break;
        case 8:
            n = pulihkanDariFile(daftar, anggaran, bulan);
            break;
        case 9:
            checkout(daftar, n, anggaran, bulan);
            break;
        case 10:
            cout << "Terima kasih telah menggunakan program belanja bulanan.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 10);

    return 0;
}
