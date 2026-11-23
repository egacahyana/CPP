#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "=== OPERATOR PENUGASAN GABUNGAN ===" << endl;
    cout << "Nilai awal x = " << x << endl;

    x += 5;
    cout << "Setelah x += 5 : " << x << endl;
    x -= 3;
    cout << "Setelah x -= 3 : " << x << endl;
    x *= 2;
    cout << "Setelah x *= 2 : " << x << endl;
    x /= 4;
    cout << "Setelah x /= 4 : " << x << endl;
    x %= 3;
    cout << "Setelah x %= 3 : " << x << endl << endl;

    cout << "=== INCREMENT & DECREMENT ===" << endl;
    int val = 5;
    cout << "Nilai awal val         : " << val << endl;
    cout << "Postfix (val++)        : " << val++ << " (Nilai saat dicetak masih 5)" << endl;
    cout << "Nilai setelah val++:   : " << val << endl;
    cout << "Prefix (++val)         : " << ++val << " (Langsung ditambah)" << endl;
    cout << "Prefix (--val)         : " << --val << " (Langsung dikurang)" << endl;

    return 0;
}
