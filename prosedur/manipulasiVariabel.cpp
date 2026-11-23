#include<iostream>
using namespace std;

void tukarNilai(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void tukarReferensi(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
int x = 10;
int y = 20;
cout << "kondisi awal X = "<< x <<", Y = "<< y <<endl;
tukarNilai(y,x);
cout << "kondisi nilai ketika sudah ditukarkan (Pass by value) X = " << x << ", Y = "<< y << endl;
tukarReferensi(x,y);
cout<<"Kondisi setelah tukar referensi (pass by referensi) X = "<< x << ", Y = "<< y <<endl;
return 0;
}
