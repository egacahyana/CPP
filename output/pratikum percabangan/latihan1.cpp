#include <iostream>

using namespace std;

int main() {
    double totalBelanja;
    char statusMember;
    double diskon = 0.0;
    double totalBayar;

    cout << "=== SISTEM PENENTUAN DISKON BELANJA ===" << endl;
    cout << "Masukkan total belanja (Rp): ";
    cin >> totalBelanja;

    cout << "Apakah Anda member? (Y/N): ";
    cin >> statusMember;

    if (statusMember == 'Y' || statusMember == 'y') {
        if (totalBelanja >= 500000) {
            diskon = 0.20; 
        } else if (totalBelanja >= 100000) {
            diskon = 0.10; 
        } else {
            diskon = 0.05; 
        }
    } else if (statusMember == 'N' || statusMember == 'n') {
        if (totalBelanja >= 500000) {
            diskon = 0.10; 
        } else {
            diskon = 0.0;
        }
    } else {
        cout << "Status member tidak valid!" << endl;
        return 1;
    }

    totalBayar = totalBelanja - (totalBelanja * diskon);
    cout << "Diskon yang diberikan: " << (diskon * 100) << "%" << endl;
    cout << "Total yang harus dibayar: Rp " << totalBayar << endl;

    return 0;
}
