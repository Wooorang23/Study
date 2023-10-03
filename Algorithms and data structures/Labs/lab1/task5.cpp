#include <iostream>
using namespace std;

template <typename T>
void pushElems(T * &arr, T * &elems, size_t len, size_t &size, size_t index);

int main() {
    size_t len = 3;
    size_t size = 4;
    size_t index = 1;

    int *arr = new int [size] {4, 8, 9, 3};
    int *elems = new int [len] {5, 9, 22};

    pushElems(arr, elems, len, size, index);

    for (size_t i = 0; i != size; ++i) {
        cout << arr[i] << endl;
    }
}

template <typename T>
void pushElems(T * &arr, T * &elems, size_t len, size_t &size, size_t index) {
    size_t newSize = size + len;
    T *newArr = new T [newSize];

    for (size_t i = 0; i != index; ++i) {
        newArr[i] = arr[i];
    }

    for (size_t i = index, j = 0; i != index + len; ++i, ++j) {
        newArr[i] = elems[j];
    }

    for (size_t i = index + len; i != newSize; ++i) {
        newArr[i] = arr[i - len];
    }

    delete [] arr;

    size += len;
    arr = newArr;
}