#include <iostream>

using namespace std;

int main() {
    int pilihan;
    int saldo = 1000000;
    double nominal;

    cout << "=== MENU TRANSAKSI ATM ===" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Penarikan Tunai" << endl;
    cout << "3. Setor Tunai" << endl;
    cout << "Pilih menu (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Saldo Anda saat ini: Rp " << saldo << endl;
            break;

        case 2:
            cout << "Masukkan nominal penarikan: Rp ";
            cin >> nominal;
            
            if (nominal <= 0) {
                cout << "Nominal penarikan tidak valid!" << endl;
            } 
            else if (nominal <= saldo) {
                saldo -= nominal;
                cout << "Penarikan berhasil. Sisa saldo: Rp " << saldo << endl;
            } else {
                cout << "Saldo tidak mencukupi!" << endl;
            }
            break;

        case 3:
            cout << "Masukkan nominal setoran: Rp ";
            cin >> nominal;
            
            if (nominal <= 0) {
                cout << "Nominal setoran tidak valid!" << endl;
            } else {
                saldo += nominal;
                cout << "Setoran berhasil. Saldo baru: Rp " << saldo << endl;
            }
            break;

        default:
            cout << "Pilihan menu tidak valid!" << endl;
            break;
    }

    return 0;
}
