#include<iostream>
#include<string>
using namespace std;

int main(){
    int kouta_kursi = 0, total_kursi_masuk = 0, total_tiket_terjual = 0, harga_tiket = 0;
    long total_pendapatan = 0;
    int usia, lansia = 0, dewasa = 0, pelajar = 0;
    char  pilihan;
    char tambah_kouta;
    string nama;

    do{
        tambah_kouta = 'n';
        cout << " Masukan Kouta kursi : ";
        cin>>kouta_kursi;

        if(kouta_kursi <= 0){
            cout << "kouta untuk kursi sudah habis mohon untuk tambahkan lagi ! ";
            break;
        }
        total_kursi_masuk += kouta_kursi;
    do{
        bool valid = true;
        cout << "=== SELAMAT DATANG DI SISTEM BIOSKOP === "<<endl;
        cout<<"Total Kouta Kursi sekarang : " << kouta_kursi << endl;
        cout << "masukan nama anda : ";
        cin >> nama;
        cout << "Masukan umur anda : ";
        cin >> usia;

        if (usia >= 60){
            cout<<"anda tergolong lansia mendapatkan harga tiket 25,000"<<endl;
            harga_tiket = 25000;
            lansia++;
        }else if (usia >= 18 && usia <= 59 ){
            cout <<"anda tergolong Dewasa mendapatkan harga tiket 50,000"<<endl;
            harga_tiket = 50000;
            dewasa++;
        }else if (usia >=5 && usia <= 17 ){
            cout << "anda tergolong pelajar mendapatkan tiket 35,000"<<endl;
            harga_tiket = 35000;
            pelajar++;
        }else{
            valid = false;
            cout<< "usia anda tidak valid"<<endl;
        }
        if (valid) {
        kouta_kursi--;
        total_tiket_terjual++;
        total_pendapatan += harga_tiket;
        }
        

        if (kouta_kursi <= 0){
            cout<< "kouta kursi anda telah habis apakah anda ingin menambahkan kouta kursi (Y/N) : ";
            cin>> tambah_kouta;
            break;
        }
        cout << "Apakah anda ingin menambahkan data lagi? Y/N : ";
        cin >> pilihan;

    }while (pilihan == 'Y' || pilihan == 'y');

    }while(tambah_kouta == 'Y' || tambah_kouta == 'y');
    
     do{
        cout<< "total harga tiket adalah :";
     }
    return 0;
}