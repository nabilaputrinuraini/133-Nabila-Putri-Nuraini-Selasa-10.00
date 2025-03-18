#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Pembelian {
    string nama;
    string jenisBensin;
    double jumlahLiter;
    int hargaPerLiter;
    double totalHarga;
    double uangDiterima;
    double kembalian;
};

const int HARGA_PERTALITE = 7000;
const int HARGA_PERTAMAX = 9000;

void inputPembelian(Pembelian &p) {
    cout << "Nama pelanggan: ";
    getline(cin, p.nama);
    
    cout << "Jenis bensin (Pertalite/Pertamax): ";
    cin >> p.jenisBensin;
    cin.ignore(); 
    
    if (p.jenisBensin == "Pertalite" || p.jenisBensin == "pertalite") {
        p.hargaPerLiter = HARGA_PERTALITE;
    } else if (p.jenisBensin == "Pertamax" || p.jenisBensin == "pertamax") {
        p.hargaPerLiter = HARGA_PERTAMAX;
    } else {
        cout << "Jenis bensin tidak tersedia!" << endl;
        exit(1);
    }
    
    cout << "Masukkan jumlah liter: ";
    cin >> p.jumlahLiter;
    
    p.totalHarga = p.jumlahLiter * p.hargaPerLiter;
    
    cout << "Uang yang diterima: ";
    cin >> p.uangDiterima;
    
    if (p.uangDiterima < p.totalHarga) {
        cout << "Uang tidak mencukupi!" << endl;
        exit(1);
    }
    
    p.kembalian = p.uangDiterima - p.totalHarga;
}

void displayStruk(const Pembelian &p) {
    cout << "\n========= STRUK PEMBELIAN =========" << endl;
    cout << left << setw(20) << "Nama Pelanggan" << ": " << p.nama << endl;
    cout << left << setw(20) << "Jenis Bensin" << ": " << p.jenisBensin << endl;
    cout << left << setw(20) << "Jumlah Liter" << ": " << fixed << setprecision(2) << p.jumlahLiter << " L" << endl;
    cout << left << setw(20) << "Harga/Liter" << ": Rp " << p.hargaPerLiter << endl;
    cout << left << setw(20) << "Total Harga" << ": Rp " << static_cast<int>(p.totalHarga) << endl;
    cout << left << setw(20) << "Uang Diterima" << ": Rp " << static_cast<int>(p.uangDiterima) << endl;
    cout << left << setw(20) << "Uang Kembalian" << ": Rp " << static_cast<int>(p.kembalian) << endl;
    cout << "===================================" << endl;
}

int main() {
    Pembelian p;
    
    inputPembelian(p);
    displayStruk(p);
    
    return 0;
}
