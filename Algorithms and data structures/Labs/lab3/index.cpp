#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(4);
    myStack.push(3);

    cout << myStack << endl;

    Queue<int> myQueue;
    
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << myQueue << endl;
}