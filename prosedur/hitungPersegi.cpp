#include<iostream>
using namespace std;

void tampilkanHeader(){
    cout<< "======================================="<<endl;
    cout<< "SELAMAT DATANG DI PROGRAM HITUNG PERSEGI"<<endl;
    cout<< "======================================="<<endl;
}
void pilihMenu(){
    cout<<"1.HitungLuas"<<endl;
    cout<<"2.Hitung Keliling"<<endl;
}
double HitungLuas(double panjang, double lebar){
    return panjang * lebar;
}

double hitungKeliling(double panjang, double lebar){
    return panjang+ lebar + panjang + lebar;
}

int main(){
    double panjang, lebar;
    char ulangi;
    int pilihan;
    
    do{
    tampilkanHeader();
    cout<< "Masukan Nilai Panjang : ";
    cin >> panjang;
    cout<< "Masukan Nilai Lebar : ";
    cin >> lebar;
    pilihMenu();
    cout<<"Pilih Hitungngan : ";
    cin >> pilihan;
    if(pilihan == 1){
        cout << "Luas : "<<HitungLuas(panjang, lebar)<<endl;
    }
    else if(pilihan == 2){
        cout<<"keliling : "<<hitungKeliling(panjang, lebar)<<endl;
    }else{
        cout<< "Program berhenti Terima kasi";
        break;
    }
    cout<<"apakah anda ingin menghitung lagi (Y/N) : ";
    cin>>ulangi;
}while(ulangi == 'Y' || ulangi == 'y');
cout <<"Program berhenti terima kasih"<<endl;
return 0;
}