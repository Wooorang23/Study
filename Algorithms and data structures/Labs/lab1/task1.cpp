#include <iostream>
using namespace std;


template <typename T>
bool isFinded(T value, size_t pos, T * &arr, size_t arrSize);

template <typename T>
void realloc(T * &arr, size_t size, size_t newSize);


int main() {
    size_t n = 5;
    size_t m = 4;
    size_t size = 0;

    int *arr1 = new int [n] {1, 2, 4, 4, 5};
    int *arr2 = new int [m] {1, 2, 4, 7};
    int *arr = new int [size];

    for (size_t i = 0; i != n; ++i) {
        if (isFinded(arr1[i], 0, arr2, m) && !isFinded(arr1[i], 0, arr, size)) {
            realloc(arr, size, size + 1);
            arr[size] = arr1[i];

            size++;
        }
    }

    for (size_t i = 0; i != size; ++i) {
        cout << arr[i] << endl;
    }

    delete [] arr;
}

template <typename T>
bool isFinded(T value, size_t pos, T * &arr, size_t arrSize) {
    bool flag = false;

    for (size_t i = pos; i != arrSize; ++i) {
        if (arr[i] == value) {
            flag = true;
            break;
        }
    }

    return flag;
}



template <typename T >
void realloc(T * &arr, size_t size, size_t newSize) {
    T *new_arr = new T [newSize];
    size = newSize;
 
    for (size_t i = 0; i != size; ++i) {
        new_arr[i] = arr[i];
    }
    
    delete [] arr;
 
    arr = new_arr;
}

