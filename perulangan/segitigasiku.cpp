#include<iostream>
using namespace std;

int main(){
    int tinggi_segitiga;

    cout<< " ==== Program Perulangan Segitiga ==== " << endl;
    cout<< "Masukan tinggi segitiga : ";
    cin>>tinggi_segitiga;

    cout<<endl;

    for (int baris = 1; baris <= tinggi_segitiga; baris++){
        for (int kolom =1; kolom <= baris; kolom++){
            cout<< "*";
        }
        cout<<endl;
    }
    return 0;
}