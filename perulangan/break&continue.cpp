#include <iostream>

using namespace std;

int main() {
    int kursi_rusak;
    int batas_kuota_vip; 

    cout << "=== PEMERIKSAAN KURSI PENONTON ===" << endl;
    cout << "Masukkan nomor kursi yang rusak: ";
    cin >> kursi_rusak;
    cout << "Masukkan batas kuota VVIP: ";
    cin >> batas_kuota_vip;
    
    for (int nomor = 1; nomor <= 10; nomor++) {
        if (nomor == batas_kuota_vip) {
            cout << "[Stop] Batas kuota tercapai pada nomor " << nomor << ". Pengecekan dihentikan (break)." << endl;
            break; 
        }
        
        if (nomor == kursi_rusak) {
            cout << "[Info] Kursi nomor " << nomor << " rusak, dilewati (continue)." << endl;
            continue;
        }
        
        cout << "Kursi nomor " << nomor << " siap digunakan." << endl;
    }
    
    cout << "Proses pemeriksaan selesai." << endl;
    return 0;
}
