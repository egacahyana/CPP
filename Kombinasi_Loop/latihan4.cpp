#include<iostream>
using namespace std;

int main(){
    int i = 1;
    int totalkelipatan3 = 0;
    while (i <= 20){
        if (i % 3 == 0){
            cout << i << " adalaah kelipatan 3" << endl; 
            totalkelipatan3 += i;
        }
        i++;
    }
    cout << "Total kelipatan 3 dari 1 sampai 20 adalah: " << totalkelipatan3 << endl;
    
    return 0;
}
