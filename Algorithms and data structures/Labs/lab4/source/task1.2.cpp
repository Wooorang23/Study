// Задача №113653. Наибольшая цифра

#include <iostream>
#include <string>

using namespace std;

char findMaxDigit(const string &input, int index, char currentMax) {
    if (index == input.length()) {
        return currentMax;
    }

    char currentDigit = input[index];

    if (currentDigit > currentMax) {
        return findMaxDigit(input, index + 1, currentDigit);
    } else {
        return findMaxDigit(input, index + 1, currentMax);
    }
}

int main() {
    string input;
    cin >> input;

    char maxDigit = findMaxDigit(input, 0, '0');
    cout << maxDigit << endl;
}
