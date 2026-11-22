#include <iostream>
#include<string>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        int nim;
        double ipk;
        string jurusan;
};

int main(){
    Mahasiswa data1;
    data1.nama = "mahasewa";
    data1.jurusan = "Teknologi Informasi";
    data1.ipk = 3.43;
    data1.nim = 1234344;

    cout<<"nama    : "<<data1.nama<<endl;
    cout<<"NIM     : "<<data1.nim<<endl;
    cout<<"Jurusan : "<<data1.jurusan<<endl;
    cout<<"IPK     : "<<data1.ipk<<endl;
    return 0;
}