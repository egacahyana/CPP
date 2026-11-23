#include <iostream>
using namespace std;

int main() {
    int harga_barang;
    int total_belanja = 0;
    int jumlah_item = 0; 

    cout << "Kasih Minimarket Sederhana" << endl;
    cout << "Masukan harga Barang (masukkan 0 untuk selesai): ";
    cin >> harga_barang;

    while (harga_barang != 0) {
        total_belanja += harga_barang;
        jumlah_item++;
        
        cout << "Masukan harga barang ke-" << (jumlah_item + 1) << " : Rp. ";
        cin >> harga_barang;
    }

    cout << "Total barang yang dibeli : " << jumlah_item << " barang" << endl;
    cout << "Total pembayaran : Rp. " << total_belanja << endl;

    return 0;
}
