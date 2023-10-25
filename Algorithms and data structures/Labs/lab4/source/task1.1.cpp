// Задача №113655. Вставить звёздочки

#include <iostream>
#include <string>

using namespace std;

void add_separator(string& str, size_t index) {
    if (index == str.length() - 1) {
        return;
    }

    str.insert(index + 1, 1, '*');

    add_separator(str, index + 2);
}

int main() {
    string input;

    cin >> input;

    add_separator(input, 0);

    cout << input << endl;
}