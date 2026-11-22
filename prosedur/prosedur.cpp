#include<iostream>
#include<string>

using namespace std;

float hitungNilaiakhir(float tugas,float kuis, float uts, float uas){
    float nilaiAkhir = (tugas * 0.10) + (kuis * 0.25) + (uts * 0.30) + (uas * 0.35);
    return nilaiAkhir;
}
float hitungRataRata(float tugas, float kuis, float uts, float uas) {
    return (tugas + kuis + uts + uas) / 4.0;
}
char tentukanGrade(float nilaiAkhir) {
    if (nilaiAkhir >= 85) return 'A';
    else if (nilaiAkhir >= 75) return 'B';
    else if (nilaiAkhir >= 60) return 'C';
    else if (nilaiAkhir >= 50) return 'D';
    else return 'E';
}
bool kelulusan(char grade){
    return (grade == 'A' || grade == 'B' || grade == 'C');
}

void tampilkanHeader(){
    cout << " ========================================="<<endl;
    cout << " SISTEM PENILAIAN AKHIR SEMESTER MAHASIGMA" <<endl;
    cout << "==========================================" <<endl;
}

void cetakLaporan(string nama, int nim, float tugas, float kuis, float uts, float uas){
    float hasilAkhir = hitungNilaiakhir(tugas, kuis, uts, uas);
    float ratarata = hitungRataRata(tugas, kuis, uts, uas);
    char grade = tentukanGrade(hasilAkhir);
    bool lulus = kelulusan(grade);

    cout << " === HASIL DARI PERHITUNGAN NILAI === "<<endl;
    cout << "Nama Mahasiswa     : "<<nama <<endl;
    cout << "Nim Mahasiswa      : "<<nim <<endl;
    cout << "Nilai Akhir        : "<<hasilAkhir <<endl;
    cout << "Rata - rata nilai  : "<<ratarata <<endl;
    cout << "Grade Nilai        : "<<grade <<endl;
    cout << "Status             : "<<(lulus ? "LULUS" : "TIDAK LULUS") <<endl;
    cout << " -----------------------------------"<<endl;

}

int main(){
    string nama;
    int nim;
    float nilaiTugas, nilaiKuis, nilaiUTS, nilaiUAS;
    char pilihan;

do{
    tampilkanHeader();
    cout <<"Silahkan memasukan data mahasiswa"<<endl;
    cout << "Masukan Nama Mahasiswa : ";
    getline (cin >> ws, nama);

    cout << "Masukan NIM : ";
    cin >> nim;
    cout <<"Masukan Nilai Tugas :";
    cin >> nilaiTugas;
    cout <<"Masukan Nilai Kuis :";
    cin >> nilaiKuis;
    cout <<"Masukan Nilai UTS :";
    cin >> nilaiUTS;
    cout <<"Masukan Nilai UAS :";
    cin >> nilaiUAS;

    cetakLaporan(nama, nim, nilaiTugas, nilaiKuis, nilaiUTS, nilaiUAS);
    cout << "apakah anda ingin menambah data lagi Y/N : ";
    cin >> pilihan;
    if (pilihan == 'n' || pilihan == 'N'){
    cout << "Program selesai terima kasih";
    break;
    }
    
}while(pilihan == 'Y' || pilihan == 'y');
return 0;
}
