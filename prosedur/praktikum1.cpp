#include <iostream>
#include <string>

using namespace std;

double hitungSubtotal(double hargaSatuan, int jumlahBeli) {
    return hargaSatuan * jumlahBeli;
}

double hitungDiskon(double subtotal, char member) {
    if ((member == 'Y' || member == 'y') && subtotal >= 100000) {
        return subtotal * 0.15;
    } 
    else if ((member == 'Y' || member == 'y') && subtotal < 100000) {
        return subtotal * 0.05;
    } 
    else if (subtotal >= 200000) {
        return subtotal * 0.10;
    } 
    else {
        return 0; 
    }
}
double hitungPajak(double setelahdiskon){
    return setelahdiskon * 0.10;
}
double hitungKembalian(double uangBayar, double totalBayar){
    return uangBayar - totalBayar;
}
void tampilkanHeader(){
    cout<< " ==================================="<<endl;
    cout<< " SELAMAT DATANG KASIR TOKO KELONTONG"<<endl;
    cout<< " ==================================="<<endl;
}
void cetakStruk(string namaKasir, string namaBarang, int jumlahBeli, bool isMember, 
                double subtotal, double diskon, double pajak, double totalBayar, 
                double uangBayar, double kembalian) {
    
    cout << "\n=========================================" << endl;
    cout << "             STRUK PEMBAYARAN            " << endl;
    cout << "=========================================" << endl;
    cout << "Kasir         : " << namaKasir << endl;
    cout << "Status        : " << (isMember ? "Member" : "Non-Member") << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Barang        : " << namaBarang << " (x" << jumlahBeli << ")" << endl;
    cout << "Subtotal      : Rp " << subtotal << endl;
    cout << "Diskon        : Rp " << diskon << endl;
    cout << "PPN (11%)     : Rp " << pajak << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Total Bayar   : Rp " << totalBayar << endl;
    cout << "Tunai         : Rp " << uangBayar << endl;
    cout << "Kembalian     : Rp " << kembalian << endl;
    cout << "=========================================" << endl;
    cout << "    Terima Kasih Telah Berbelanja!       " << endl;
}

int main(){
    string nama, namaBarang;
    double hargaSatuan, uangBayar, subtotal, diskon, pajak, totalBayar, kembalian;
    int jumlahBeli;
    char inputMember, pilihan;
    do{
        tampilkanHeader();
        cout << "Masukan Nama kasir : ";
        getline(cin >> ws, nama);
        cout <<"Masukan Nama Barang : ";
        getline(cin >> ws, namaBarang);
        do {
        cout <<"Masukan Harga Satuan Barang : ";
         cin >> hargaSatuan;
        if(hargaSatuan <= 0){
            cout<<"harga barang tidak boleh kosong Ulangi!\n";
        }
        }while(hargaSatuan <= 0);
        do {
        cout <<"Masukan Jumlah Beli : ";
        cin >>jumlahBeli;
        if(jumlahBeli <= 0){
            cout <<"jumlah tidak boleh 0 Ulangi!\n";
        }
        }while(jumlahBeli <= 0);
        cout << "Status Member : ";
        cin >> inputMember;
        bool isMember = (inputMember == 'Y' || inputMember == 'y');

        subtotal   = hitungSubtotal(hargaSatuan, jumlahBeli);
        diskon     = hitungDiskon(subtotal, inputMember);
        pajak      = hitungPajak(subtotal - diskon);
        totalBayar = (subtotal - diskon) + pajak;

        cout <<"Total Yang harus anda bayar : " <<totalBayar<<endl;
        do{
            cout <<"Masukan Jumlah Uang anda : ";
            cin >> uangBayar;
            if (uangBayar <= 0 ){
                cout <<"Jumlah Uang anda tidak valid Ulangi\n";
            }else if(totalBayar < uangBayar){
                cout <<"Pembayaran berhasil";
                break;
            }
        }while(uangBayar > totalBayar);

        kembalian = hitungKembalian(uangBayar,totalBayar);

        cetakStruk(nama, namaBarang, jumlahBeli, isMember, subtotal, diskon, pajak, totalBayar, uangBayar, kembalian);

    cout << "Apakah Anda ingin Menambah data lagi : ";
    cin >> pilihan;
    }while(pilihan == 'Y' || pilihan == 'y');
    
    return 0;
    
}