    #include<iostream>
    using namespace std;

    int main(){
        int pilihan, jumlahBeli;
        double totalBelanja = 0, harga = 0, diskon = 0;
        do {
            cout << "=== Program kasih seherhana ===" << endl;
            cout << "1. Buku Novel  (Rp.130.000)" << endl;
            cout << "2. Buku Komik  (Rp.100.000)" << endl;
            cout << "3. Buku Ensiklopedia  (Rp.150.000)" << endl;
            cout << "4. Buku Pelajaran  (Rp.200.000)" << endl;
            cout << "5. Selesai & hitung pembayaran" << endl;
            cout << "Masukkan pilihan (1-5): ";
            cin >> pilihan;
            if (pilihan >= 1 && pilihan <=4){
                cout << "Masukkan jumlah buku: ";
                cin >> jumlahBeli;
                switch (pilihan){
                    case 1:
                        harga = 130000;
                        break;
                    case 2:
                        harga = 100000;
                        break;
                    case 3:
                        harga = 150000;
                        break;
                    case 4:
                        harga = 200000;
                        break;
                }
                totalBelanja += harga * jumlahBeli;
            }
        } while (pilihan != 5);
        cout << "Total belanja: Rp." << totalBelanja << endl;
        if (totalBelanja >= 500000){
            diskon = totalBelanja * 0.1;
            cout << "Anda mendapatkan diskon 10%: Rp." << diskon << endl;
        } else if (totalBelanja >= 300000){
            diskon = totalBelanja * 0.05;
            cout << "Anda mendapatkan diskon 5%: Rp." << diskon << endl;
        } else {
            cout << "Tidak ada diskon yang diberikan." << endl;
        }
        cout<<"============== Detail Pembayaran =============="<<endl;
        cout << "Total belanja sebelum diskon: Rp." << totalBelanja << endl;
        cout << "Diskon: Rp." << diskon << endl;
        cout << "Total yang harus dibayar: Rp." << (totalBelanja - diskon) << endl;
        return 0;
    }