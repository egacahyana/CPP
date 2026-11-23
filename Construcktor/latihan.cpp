#include<iostream>
#include<string>

using namespace std;
class latihan{
    public:
        string dataString;
        int dataInteger;
};
class Mahasiswa{
    public:
    string nama;
    string NIM;
    string jurusan;
    double IPK;

        Mahasiswa(string inputNama, string inputNIM, string inputJurusan,double inputIPK ){
            Mahasiswa::nama = inputNama;
            Mahasiswa::NIM = inputNIM;
            Mahasiswa::jurusan = inputJurusan;
            Mahasiswa::IPK = inputIPK;
        }
};
int main (){

 Mahasiswa mahasiswa1 = Mahasiswa("Mahasigma1", "2003130", "Teknologi Informasi", 3.67);
 cout << mahasiswa1.nama <<endl;
 cout << mahasiswa1.NIM <<endl;
 cout << mahasiswa1.jurusan <<endl;
 cout << mahasiswa1.IPK <<endl;
 
Mahasiswa mahasiswa2 = Mahasiswa("Mahasigma2", "2003131", "Teknologi Informasi", 3.90);
 cout << mahasiswa2.nama <<endl;
 cout << mahasiswa2.NIM <<endl;
 cout << mahasiswa2.jurusan <<endl;
 cout << mahasiswa2.IPK <<endl;
 
 
return 0;
}