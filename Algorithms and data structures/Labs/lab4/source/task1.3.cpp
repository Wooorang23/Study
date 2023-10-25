// Задача №113654. Количество цифр

#include <iostream>
#include <string>

using namespace std;

int countDigits(const string &input) {
    int count = 0;
    for (char c : input) {
        if (isdigit(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;

    int digitCount = countDigits(input);
    cout << digitCount << endl;

    return 0;
}
