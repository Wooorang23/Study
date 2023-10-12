#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

bool isValid(std::string s) {
    Stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }

            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    string input_string = "([])";

    bool result = isValid(input_string);
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}