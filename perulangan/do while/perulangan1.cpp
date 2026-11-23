#include<iostream>
using namespace std;


int main(){
int batas_perulangan;

 cout<< " ==== Program Perulangan For ==== " << endl;
 cout<< "Masukan batas perulangan : ";
 cin>>batas_perulangan;
 for (int i = 1; i <= batas_perulangan; i+=2){
    cout<< i << " ";
    cout<< "Perulangan Ke-" << i << endl;

 }
}