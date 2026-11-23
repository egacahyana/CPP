#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int nilaip;
	int nilaiq;
	
	cout<< boolalpha;
	cout<< " ==== Operator Rasional ==== "<<endl;
	cout<< "Masukan Nilai p :";
	cin >> nilaip;
	cout<<"Masukan Nilai q :";
	cin>>nilaiq;
	
	cout << "p == q : " << (nilaip == nilaiq) << endl;
	cout << "p != q : " << (nilaip != nilaiq) << endl;
	cout << "p > q : " << (nilaip > nilaiq) << endl;
	cout << "p < q : " << (nilaip < nilaiq) << endl;
	cout << "p >= q : " << (nilaip >= nilaiq) << endl;
	cout << "p <= q : " << (nilaip <= nilaiq) << endl;

return 0;

	
}