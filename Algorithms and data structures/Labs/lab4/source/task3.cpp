// Задача №153. N-ое число Фибоначчи

#include <iostream>

using namespace std;

int fibonacchi(int n) {
    if (n == 0) return 0;

    if (n == 1) return 1;

    return fibonacchi(n - 2) + fibonacchi(n - 1);
}


int main() {
    int n;

    cin >> n;

    cout << fibonacchi(n) << endl;
}