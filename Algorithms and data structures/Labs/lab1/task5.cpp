#include <iostream>
using namespace std;

template <typename T>
void pushElems(T * &arr, T * &elems, int len, int size, int index);

int main() {
    int len = 3;
    int size = 4;
    int index = 1;

    int *arr = new int [size] {4, 8, 9, 3};
    int *elems = new int [len] {5, 9, 22};

    pushElems(arr, elems, len, size, index);
}

template <typename T>
void pushElems(T * &arr, T * &elems, int len, int size, int index) {
    int newSize = size + len;
    int *newArr = new int [newSize];

    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = index, j = 0; i < index + len; ++i, ++j) {
        newArr[i] = elems[j];
    }

    for (int i = index + len; i < newSize; ++i) {
        newArr[i] = arr[i - len];
    }

    delete [] arr;
    arr = newArr;
}