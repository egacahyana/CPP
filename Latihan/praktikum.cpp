#include <iostream>
#include <string>
using namespace std;

int main() {
	//variabel
   	int umur = 19;
   	double ipk = 3.50;
   	char indeksNilai = 'A';
   	bool statusAktif = true;
   	string namaMahasiswa = "budiono siregar";
   	string namaKelas;
	
	//menampilkan output 
	cout << "===== Data Mahasiswa ====="<<endl;
	cout << "Nama : " << namaMahasiswa <<endl;
	cout << "Umur : " << umur <<endl;
	cout << "IPK : " <<ipk <<endl;
	cout << "Kelas : ";
	cin >> namaKelas;
	cout << "Indeks Nilai : " <<indeksNilai <<endl;
	cout << "Aktif : " << (statusAktif ? "ya" : "tidak ") << endl;
    return 0;
}
