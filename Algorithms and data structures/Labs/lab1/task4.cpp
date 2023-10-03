#include <iostream>
using namespace std;

template <typename T>
void pushBack(T * &arr, T * &elems, size_t &size, size_t len);

int main() {
    size_t n = 5; 
    size_t len = 4;

    int *arr = new int [n] {1, 2, 3, 4, 5};
    int *elems = new int [len] {11, 6, 7, 85};
    
    pushBack(arr, elems, n, len);

    cout << n;
}

template <typename T>
void pushBack(T * &arr, T * &elems, size_t &size, size_t len) {
    T *newArr = new T [size + len];

    size_t i = 0;
    size_t j = 0;

    while (i != size) {
        newArr[i] = arr[i];

        ++i;
    }

    while (i != size + len) {
        newArr[i] = elems[j];

        ++i;
        ++j;
    }

    delete [] arr;

    size += len;
    arr = newArr;
}