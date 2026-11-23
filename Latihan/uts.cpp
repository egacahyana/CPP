#include <iostream>
#include <string>

using namespace std; // Perbaikan 1: Tambah titik koma

int main() {
    int stokVaksin;
    int lansia = 0, dewasa = 0, anak = 0;
    int totalTerlayani = 0;

    cout << "=== SISTEM ANTREAN VAKSIN KELILING ===" << endl;
    cout << "Masukkan jumlah stok vaksin hari ini: ";
    cin >> stokVaksin;

    // Perbaikan 4: Validasi stok awal tidak boleh <= 0 
    if (stokVaksin <= 0) {
        cout << "Jumlah stok vaksin tidak valid atau kosong." << endl;
        return 0;
    }

    while (stokVaksin > 0) {
        string nama;
        int usia;

        cout << "\n--- Pendaftaran Peserta ---" << endl;
        cout << "stok vaksin sekarang adalah : "<< stokVaksin <<endl;
        cout << "Nama: ";
        getline(cin >> ws, nama); // Perbaikan 3: Bisa membaca spasi
        
        cout << "Usia: ";
        // Perbaikan 4: Validasi usia tidak boleh negatif
        if (usia < 0) {
            cout << "Usia tidak valid! Silakan ulangi pendaftaran." << endl;
            continue;
        }

        // Perbaikan 2: Gunakan && (AND) agar rentang usia tepat
        if (usia >= 60) {
            cout << nama << " mendapatkan vaksin (Kategori: Lansia)." << endl;
            lansia++;
        } else if (usia >= 18 && usia < 60) {
            cout << nama << " mendapatkan vaksin (Kategori: Dewasa)." << endl;
            dewasa++;
        } else {
            cout << nama << " mendapatkan vaksin (Kategori: Anak-anak)." << endl;
            anak++;
        }

        stokVaksin = stokVaksin - 1;
        totalTerlayani++;

        cout << "Sisa vaksin: " << stokVaksin << endl;
    }

    cout << "\n======================================" << endl;
    cout << "STOK VAKSIN HABIS. PENDAFTARAN DITUTUP." << endl;
    cout << "Total warga terlayani: " << totalTerlayani << endl;
    cout << "- Lansia    : " << lansia << " orang" << endl;
    cout << "- Dewasa    : " << dewasa << " orang" << endl;
    cout << "- Anak-anak: " << anak << " orang" << endl;

    return 0;
}