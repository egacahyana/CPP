#include<iostream>
using namespace std;

int main(){
    string username = "admin";
    string inputUsername;
    const int PIN_benar = 1234;
    int inputPIN;
    int percobaan = 3;
    bool statusLogin = false;

    cout << "=== Program Login Sederhana ===" << endl;
    while (percobaan > 0){
        cout << "Masukkan Username: ";
        cin >> inputUsername;
        cout << "Masukkan PIN (4 digit): ";
        cin >> inputPIN;

        if (inputPIN == PIN_benar && inputUsername == username) {
            cout << "Login berhasil!" << endl;
            statusLogin = true;
            break;
        } else {
            percobaan--;
            if (percobaan > 0){
                cout << "PIN salah! Sisa percobaan anda : " << percobaan << endl;
            } else {
                cout << "PIN salah! Akun anda diblokir." << endl;
            }
        }
    }
    cout <<"--------------------------" << endl;
    if (statusLogin) {
        cout << "Selamat datang!" << endl;
    } else {
        cout << "Akun diblokir. Silakan hubungi admin." << endl;
    }

    return 0;
}
