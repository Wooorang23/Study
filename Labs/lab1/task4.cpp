#include <iostream>
using namespace std;

template <typename T>
void pushBack(T * &arr, T elems[], int size, int len);

int main() {
    int n = 5; 
    int len = 4;

    int *arr = new int [n] {1, 2, 3, 4, 5};
    int elems[len] = {11, 6, 7, 85};
    
    pushBack(arr, elems, n, len);

    for (int i = 0; i < n + len; ++i) {
        cout << arr[i] << endl;
    } 
}

template <typename T>
void pushBack(T * &arr, T elems[], int size, int len) {
    int *newArr = new int [size + len];

    int i = 0;
    int j = 0;

    while (i < size) {
        newArr[i] = arr[i];

        ++i;
    }

    while (i < size + len) {
        newArr[i] = elems[j];

        ++i;
        ++j;
    }

    delete [] arr;

    arr = newArr;
}