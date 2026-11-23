#include <iostream>
using namespace std;

int main() {
    int nilaiUjian;
    int presensi; 
    cout << "=== OPERATOR LOGIKA ===" << endl;
    cout << "Masukan Nilai ujian :";
    cin>> nilaiUjian;
	cout<<" Masukan Presensi :";
	cin>>presensi;
	
    bool lulusUjian = nilaiUjian >= 75;
    bool lulusPresensi = presensi >= 75;
    bool lulusMatakuliah = lulusUjian && lulusPresensi;
    
    cout << "Lulus Ujian (>= 75)   : " << lulusUjian << endl;
    cout << "Lulus Presensi (>= 75): " << lulusPresensi << endl;
    cout << "Kelulusan Akhir (AND) : " << (lulusMatakuliah ? "LULUS" : "TIDAK LULUS") << endl << endl;
    
    bool tugasBonus = true;
    bool dapatRemedial = !lulusUjian || tugasBonus;
    
    cout << "Kondisi Remedial (OR/NOT) : " << (dapatRemedial ? "Ya" : "Tidak") << endl;
    
    return 0;
}
