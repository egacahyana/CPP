#include<iostream>
using namespace std;

double volume(double sisi){
    return sisi * sisi * sisi;
}
double inputValid(string pesan){
    double nilai;
    cout<< pesan;
    cin>> nilai;
    while(nilai <= 0){
        cout<< "Nilai tidak boleh kosong atau negatif : ";
        cin>> nilai;
    }
    return nilai;
}
double volume(double panjang, double lebar, double tinggi){
    return panjang * lebar * tinggi;
}

double volume(double Jarijari, double tinggi){
    const double phi = 3.14;
    return phi * Jarijari * Jarijari * tinggi;
}
void tampilkanMenu(){
    cout<<"1. Hitung Volume Kubus"<<endl;
    cout<<"2. Hitung Volume Balok"<<endl;
    cout<<"3. Hitung Volume Tabung"<<endl;
}
int main (){
    double sisi, panjang, lebar, tinggiBalok, jariJari, tinggiTabung;
    int pilih;
    char ulangi;

    do{
    cout<<"Selamat datang dimenu hitung bentuk benda"<<endl;
    tampilkanMenu();
    cout<<"Pilih Menu hitungan : ";
    cin >> pilih;
    switch (pilih){
    case 1:
        sisi = inputValid("Masukan sisi : ");
        cout<< "Hasil Luas kubus adalah : " << volume(sisi)<<endl;
        break;
    case 2:
      panjang = inputValid("Masukan panjang : ");
      lebar = inputValid("Masukan Lebar : ");
      tinggiBalok = inputValid("Masukan Tinggi : ");
      cout<< "Volume balok : " <<volume(panjang, lebar, tinggiBalok) << endl;
      break;
    case 3:
       cout<< "Phi digunakan adalah 3.14"<<endl;
       jariJari = inputValid("Masukan Jari - jari : ");
       tinggiTabung = inputValid("Masukan Tinggi Tabung : ");
       cout<< "Volume tabung " <<volume(jariJari, tinggiTabung)<<endl;
       break;
    }
    cout<< "apakah anda ingin menambahkan data lagi? (Y/N) : ";
    cin>> ulangi;

}while(ulangi == 'Y' || ulangi == 'y');
cout<<"Program telah berakhir terima kasi ";
return 0;
}