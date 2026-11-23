#include <iostream>

using namespace std;

int main() {
    int a, b; 
    
    cout << "=== OPERATOR ARITMATIKA ===" << endl;
    
    cout << "Masukkan Nilai a : ";
    cin >> a;
    cout << "Masukkan Nilai b : ";
    cin >> b;
    cout << endl;
    
    cout << "Penjumlahan (a + b) : " << (a + b) << endl;
    cout << "Pengurangan (a - b) : " << (a - b) << endl;
    cout << "Perkalian   (a * b) : " << (a * b) << endl;
    cout << "Pembagian   (a / b) : " << (a / b) << " (Pembagian Bulat)" << endl;
    cout << "Sisa Bagi   (a % b) : " << (a % b) << " (Modulo)" << endl;
    
    
    double hasilPresisi = (double)a / b;
    cout << "Pembagian Desimal   : " << hasilPresisi << endl;
    
    return 0;
}
