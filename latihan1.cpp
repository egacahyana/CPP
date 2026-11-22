#include<iostream>
using namespace std;

int main(){
    int jumlahMhs;
    float nilai;
    int Lulus = 0, tidakLulus = 0;
    
    cout<<" === Program menghitung nilai mahasiswa === "<<endl;
    cout<<"Masukkan jumlah mahasiswa : ";
    cin>>jumlahMhs;

    for (int i = 1; i <= jumlahMhs; i++) {
        cout<<"Masukkan nilai mahasiswa ke-"<<i<<": ";
        cin>>nilai;
        if (nilai < 0 || nilai > 100) {
            cout<<"Nilai tidak valid. Silakan masukkan nilai antara 0 hingga 100."<<endl;
            i--; 
            continue;
        }
        if(nilai >= 80){
            cout<<"Mahasiswa ke-"<<i<<" Lulus"<< "grade: A"<<endl;
            Lulus++;
        } else if(nilai >= 60){
            cout<<"Mahasiswa ke-"<<i<<"Lulus"<< "grade: B"<<endl;
            Lulus++;
        } else if (nilai >= 50){
            cout<<"Mahasiswa ke-"<<i<<"Lulus bersyarat"<< "grade: C"<<endl;
            Lulus++;
        }else{
            cout<<"Mahasiswa ke-"<<i<<"Tidak Lulus"<< ";grade: D"<<endl;
            tidakLulus++;
    }
}
cout<<"Jumlah mahasiswa yang lulus : "<<Lulus<<endl;
cout<<"Jumlah mahasiswa yang tidak lulus : "<<tidakLulus<<endl;
}