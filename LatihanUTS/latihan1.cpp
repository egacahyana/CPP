#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void tampilkanHeader() {
    cout << " ===========================\n";
    cout << " SISTEM KASIR CAFE MAHASISWA\n";
    cout << " ===========================\n";
}
void tampilkanMenu() {
    cout << " --- Daftar Menu ---\n";
    cout << "1. Kopi Hitam         Rp 5.000\n";
    cout << "2. Matcha Latte       Rp 10.000\n";
    cout << "3. Roti Bakar         Rp 7.000\n";
    cout << "4. Kentang Goreng     Rp 8.000\n";
}


void cetakStruk(string pelanggan, vector<int>noAntrean, vector<string>namaPesanan, vector<short>jumlahPesanan, vector<int>hargaSatuan, vector<int> subHargaitem, int subtotal, double diskon, double ppn,string namaKasir, double totalPembarayan) {
    cout << "\n============================\n";
    cout << " STRUK PEMBELIAN MAHASISWA \n";
    cout << "============================\n";
    cout << "Nama Pelanggan : " << pelanggan << endl;
    cout << "Nomor Antrean : " << noAntrean[0] << endl;
    cout << "----------------------------\n";

    for(int i = 0; i < namaPesanan.size(); i++) {
        cout << namaPesanan[i] << "\n";
        cout << "   " << jumlahPesanan[i] << " x Rp " << hargaSatuan[i] 
             << " = Rp " << subHargaitem[i] << "\n";
    }
    
    cout << "-----------------------------\n";
    cout << fixed << setprecision(0);
    cout << "Subtotal         : Rp " << subtotal << "\n";
    cout << "Diskon (10%)     : Rp " << diskon << "\n";
    cout << "PPN (11%)        : Rp " << ppn << "\n";
    cout << "Nama Kasir       : " << namaKasir << "\n";
    cout << "-----------------------------\n";
    cout << "Total Pembayaran : Rp "<< totalPembarayan << "\n";
    cout << "============================\n";
    cout << "Terima Kasih Telah Berbelanja di Cafe Mahasiswa\n";
    cout << "============================\n";
}

int main() {
    vector<string> namaPesanan;
    vector<short> jumlahPesanan;
    vector<int> hargaSatuan;
    vector<int> subHargaitem;

    string namaKasir = "Bayu Saputra";
    string pelanggan;
    double jumlahUang = 0;
    char pesanLagi = 0;
    int pilihanMenu, kuantitas;
    vector<int> noAntrean;
    
    double subtotalKeseluruhan = 0, diskon = 0, ppn = 0, totalPembarayan = 0;
    
    tampilkanHeader();
    cout << "Masukkan Nama Pelanggan : ";
    getline(cin, pelanggan);

    do {
        tampilkanMenu();
        cout << "Masukkan Pilihan Menu (1-4) : ";
        cin >> pilihanMenu;
        cout << "Masukkan Jumlah Pesanan : ";
        cin >> kuantitas;
        
        string menuSementara = "";
        int hargaSementara = 0;

        switch(pilihanMenu) {
            case 1:
                menuSementara = "Kopi Hitam";
                hargaSementara = 5000;
                break;
            case 2:
                menuSementara = "Matcha Latte";
                hargaSementara = 10000;
                break;
            case 3:
                menuSementara = "Roti Bakar";
                hargaSementara = 7000;
                break;
            case 4:
                menuSementara = "Kentang Goreng";
                hargaSementara = 8000;
                break;
            default:
                cout << "Pilihan Menu Tidak Tersedia\n";
                continue;
        }
        
        namaPesanan.push_back(menuSementara);
        hargaSatuan.push_back(hargaSementara);
        jumlahPesanan.push_back(kuantitas);
        noAntrean.push_back(noAntrean.size() + 1);
        int subHarga = hargaSementara * kuantitas;
        subHargaitem.push_back(subHarga);
        subtotalKeseluruhan += subHarga;

        cout << "Apakah ada pesanan tambahan? (Y/T): ";
        cin >> pesanLagi;

    }while (pesanLagi == 'Y' || pesanLagi == 'y');

    if (subtotalKeseluruhan > 100000) {
        diskon = subtotalKeseluruhan * 0.1;
    }
    
    double hargaSetelahDiskon = subtotalKeseluruhan - diskon;
    ppn = hargaSetelahDiskon * 0.11;
    totalPembarayan = hargaSetelahDiskon + ppn;
    
    cetakStruk(pelanggan, noAntrean, namaPesanan, jumlahPesanan, hargaSatuan, subHargaitem,subtotalKeseluruhan, diskon, ppn, namaKasir,totalPembarayan);
               
    cout << "masukan jumlah uang yang dibayarkan : ";
    cin >> jumlahUang;
    if (totalPembarayan > jumlahUang) {
        cout << "Uang yang dibayarkan kurang dari total pembayaran. Silakan coba lagi." << endl;
        return 1;
    }
    double kembalian = jumlahUang - totalPembarayan;
    cout << "Kembalian : Rp " << kembalian << endl;
    return 0;
}