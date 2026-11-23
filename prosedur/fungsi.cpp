#include<iostream>
using namespace std;

double volume(double sisi){
        return sisi * sisi * sisi;
} 

double volume(double panjang, double lebar, double tinggi){
    return panjang * lebar * tinggi;
}
double volume(double jariJari, double tinggi){
    const double phi = 3.14;
    return phi * tinggi * jariJari * jariJari; 
}

int main(){
    cout<< "Volume kubus (sisi 4) : "<< volume(4.0)<<endl;
    cout << "Volume balok (p: 5, l: 3, t: 2) : " << volume(5.0, 3.0, 2.0)<<endl;
    cout << "Volume Tabung (r : 7, t : 10) : "<< volume(7.0, 10.0)<<endl;
}
