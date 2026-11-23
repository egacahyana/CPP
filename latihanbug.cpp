#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nilai = {80, 75, 90, 85, 100};
    int total = 0;

    // Menghitung total nilai
    for(int i = 0; i < nilai.size(); i++) {
        total += nilai[i];
    }

    float rataRata = static_cast<float>(total) / nilai.size();

    cout << "Total Nilai: " << total << "\n";
    cout << "Rata-rata: " << rataRata << "\n";

    return 0;
}