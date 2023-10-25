// Задача №199. НОД

#include <iostream>

using namespace std;

int nod(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }

    if (a > b) {
        return nod(a % b, b);
    } else {
        return nod(a, b % a);
    }
}

int main() {
    int a, b;
    
    cin >> a;
    cin >> b;

    cout << nod(a, b) << endl;
}