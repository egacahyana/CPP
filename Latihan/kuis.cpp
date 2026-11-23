#include<iostream>
#include<string>
using namespace std;

int main(){
string nama;
int lansia = 0, dewasa = 0, anak = 0, totalDilayani = 0;
int stokVaksin;
int usia;
char pilihan;

cout << "masukan stok vaksin : ";
cin >> stokVaksin;


if (stokVaksin <=0){
    cout << "stok vaksin habis" << endl;
    return 0;
}
do{
    cout << " === Selamat datang di program vaksinasi ===" << endl;
    cout << "masukan nama : ";
    cin >> nama;
    cout << "masukan usia : ";
    cin >> usia;

    if (usia >= 60){
        lansia++;
    } else if (usia >= 18){
        dewasa++;
    } else {
        anak++;
    }
    totalDilayani++;
    stokVaksin--;

    cout << "data berhasil diinput" << endl;
    cout << "apakah ada orang lain yang ingin divaksin? (Y/T) : ";
    cin >> pilihan;
    cout << "stok vaksin tersisa : " << stokVaksin << endl;
    if (stokVaksin <= 0){
        cout << "stok vaksin habis" << endl;
        break;
    }
}while (pilihan == 'Y' || pilihan == 'y');
cout << "============================" << endl;
cout << "Total orang yang dilayani: " << totalDilayani << endl;
cout << "Jumlah lansia: " << lansia << endl;
cout << "Jumlah dewasa: " << dewasa << endl;
cout << "Jumlah anak: " << anak << endl;
cout << " Program selesai" << endl;
}