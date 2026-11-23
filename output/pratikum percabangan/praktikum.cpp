#include<iostream>
using namespace std;

int main(){
   string nama;
   int usia;
   float jam;
   double diskonUsia = 0.0;
   int pilihan;
   double hargaDasar = 0.0;
   double totalHarga = 0.0;

   cout << "=== SISTEM PENENTUAN DISKON BIOSKOP ===" << endl;
   cout << "1.Hari kerja Senin - kamis " << endl;
   cout << "2.Hari jumat " << endl;
   cout << "3.Weekend Sabtu - Minggu" << endl;
   cout << "Pilih menu (1-3): ";
   cin >> pilihan;

   if (pilihan < 1 || pilihan > 3) {
       cout << "Pilihan menu tidak valid!" << endl;
       return 1;
   }
   cout << " Masukan Nama : ";
   cin >> nama;

   cout << "Masukkan usia: ";
   cin >> usia;

   if (usia < 0) {
       cout << "Usia tidak valid!" << endl;
       return 1;
   }

   cout << "Masukkan jam masuk: ";
   cin >> jam;

   if (jam < 0 || jam > 23) {
       cout << "Jam tidak valid!" << endl;
       return 1;
   }

   if (pilihan == 1) {
       hargaDasar = 40000;
       if (usia <= 12) {
           diskonUsia = 0.20;
       } else if (usia >= 60) {
           diskonUsia = 0.30;
       }
   } else if (pilihan == 2) {
       hargaDasar = 50000;
       if (usia <= 12) {
           diskonUsia = 0.20;
       } else if (usia >= 60) {
           diskonUsia = 0.30;
       }
   } else if (pilihan == 3) {
       hargaDasar = 60000;
       if (usia <= 12) {
           diskonUsia = 0.20;
       } else if (usia >= 60) {
           diskonUsia = 0.30;
       }
   }

   system("cls");
   totalHarga = hargaDasar - (hargaDasar * diskonUsia);
   cout << "=== RINCIAN TIKET BIOSKOP ===" << endl;
   cout << "Nama: " << nama << endl;
   cout << "Usia: " << usia << endl;
   cout << "Harga tiket dasar: Rp " << hargaDasar << endl;
   cout << "Potongan diskon: Rp " << (hargaDasar * diskonUsia) << endl;
   cout << "Total harga tiket akhir: Rp " << totalHarga << endl;

   return 0;
}
