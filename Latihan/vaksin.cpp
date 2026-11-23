#include<iostream>
#include<string>
using namespace std;

int main(){
    int lansia = 0, dewasa = 0, anak_anak = 0, remaja = 0, total_vaksin = 0;
    int stok_Vaksin, usia, total_terlayani = 0; 
    string nama;
    char pilihan, tambah_stok;

    do {
        tambah_stok = 'N';
        cout << "masukan Stok vaksin : ";
        cin >> stok_Vaksin;

        if(stok_Vaksin <= 0){
            cout << "Vaksin anda telah habis mohon untuk isi ulang ";
            break;
        }
        total_vaksin += stok_Vaksin;
    do{
        cout << " === SELAMAT DI DATANG SISTEM VAKSINASI === "<<endl;

        cout << "Total Vaksin Anda Sekarang adalah : "<<stok_Vaksin <<endl;
        cout << "Masukan Nama :";
        cin>> nama;
        cout << "masukan usia :";
        cin>> usia;

        if(usia >= 60){
            cout<<"anda tergolong lansia " <<endl;
            lansia++;
        }else if(usia >= 20 ){
            cout<<"anda tegolong dewasa" <<endl;
            dewasa++;
        }else if (usia >= 10){
            cout <<"anda tergolong remaja" <<endl;
            remaja++;
        }else if (usia >= 0){
            cout<< "anda tergolong anak anak" <<endl;
            anak_anak++;
        }else{
            cout<<"input tidak valid" <<endl;
        }
        total_terlayani++;
        stok_Vaksin--;

        if (stok_Vaksin <= 0 ){
            cout << "Stok vaksin anda habis apakah anda ingin Menambahkan stok vaksin | Y/N : ";
            cin >> tambah_stok;
            break;
        }
        cout << "Apakah anda ingin menambahkan data lagi ? Y/N : ";
        cin >> pilihan;
    }while (pilihan == 'Y' || pilihan == 'y');
}while (tambah_stok == 'Y' || tambah_stok == 'y');
    cout << " === REKAP DATA VAKSINASI ===" << endl;
    cout << "Total Stok Vaksin Masuk : " << total_vaksin << endl;
    cout << "Total Terlayani         : " << total_terlayani << endl;
    cout << "- Lansia                : " << lansia << endl;
    cout << "- Dewasa                : " << dewasa << endl;
    cout << "- Remaja                : " << remaja << endl;
    cout << "- Anak-anak             : " << anak_anak << endl;

    return 0;
}        
        
        
       









