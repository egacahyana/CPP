#include<iostream>
using namespace std;

int main(){
    int nilai;
    cout << "masukan nilai : ";
    cin >> nilai;
    switch (nilai){
        case 51 ... 60:
            cout << "anda mendapatkan nilai E" << endl;
            break;
        case 61 ...70:
            cout << "anda mendapatkan nilai D" << endl;
            break;
        case 71 ... 80:
            cout << "anda mendapatkan nilai C" << endl;
            break;
        case 81 ... 90:
            cout << "anda mendapatkan nilai B" << endl;
            break;
        case 91 ... 100:
            cout << "anda mendapatkan nilai A" << endl;
            break;
        default:
            cout << "nilai yang anda masukan salah" << endl;
    }
    return 0;
}