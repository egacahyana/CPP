#include <iostream>
#include <string>

using namespace std;

void tampilkanHasil(int lansia, int dewasa, int anak, int total) {
    cout << "\n=== HASIL AKHIR ANTREAN VAKSIN ===" << endl;
    cout << "Jumlah Lansia   : " << lansia << endl;
    cout << "Jumlah Dewasa   : " << dewasa << endl;
    cout << "Jumlah Anak-anak: " << anak << endl;
    cout << "Total Terlayani : " << total << endl;
}

int main() {
    int lansia = 0;
    int dewasa = 0;
    int anak = 0;
    int totalTerlayani = 0;
    int stokVaksin;

    cout << "Masukkan stok vaksin: ";
    cin >> stokVaksin;

    if (stokVaksin <= 0) {
        cout << "Input tidak valid" << endl;
        return 0;
    }

    while (stokVaksin > 0) {
        string nama;
        int usia;

        cout << "\nMasukkan nama: ";
        cin >> nama;
        cout << "Masukkan usia: ";
        cin >> usia;

        if (usia > 60) {
            lansia++;
        } else if (usia >= 18) {
            dewasa++;
        } else {
            anak++;
        }

        totalTerlayani++;
        stokVaksin--;
    }

    tampilkanHasil(lansia, dewasa, anak, totalTerlayani);

    return 0;
}