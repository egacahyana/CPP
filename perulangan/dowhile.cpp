#include<iostream>
using namespace std;

int main(){
    int pilihan;
    double suhu_celcius , conversi_suhu;

    do{
        cout << "==== Program Konversi Suhu ====" << endl;
        cout << "1. Celcius ke Fahrenheit" << endl;
        cout << "2. Celcius ke Kelvin" << endl;
        cout << "3. Exit" << endl;
        cout << "Masukan Pilihan : ";
        cin >> pilihan;

        if(pilihan == 1){
            cout << " Masukan Suhu Celsius : ";
            cin >> suhu_celcius;
            conversi_suhu = (suhu_celcius * 9.0/5.0) + 32;
            cout << "Hasil konversi celcius ke fahrensheit "<< conversi_suhu <<endl;
        }else if (pilihan == 2){
            cout << " Masukan Suhu Celsius : ";
            cin >> suhu_celcius;
            conversi_suhu = suhu_celcius + 273.15;
            cout << "Hasil konversi celcius ke kelvin "<< conversi_suhu <<endl;
        }else if (pilihan != 3){
            cout << "Pilihan tidak valid" << endl;
        }
    }while(pilihan != 3);
    cout<< "Terima kasih telah menggunakan program konversi suhu" << endl;
}