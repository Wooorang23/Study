#include <iostream>
using namespace std;

template <typename T>
bool isFinded(T value, T pos, T arr[], T arrSize);

template <typename T>
void realloc(T * &arr, size_t size, size_t newSize);


int main() {
    int n = 5;
    int m = 4;
    int size = 0;

    int arr1[n] = {1, 1, 4, 4, 5};
    int arr2[m] = {2, 3, 8, 7};

    int *arr = new int[size];

    for (int i = 0; i != n; ++i) {
        if (!isFinded(arr1[i], i, arr2, m) && !isFinded(arr1[i], i + 1, arr1, n)) {
            realloc(arr, size, size + 1);
            arr[size] = arr1[i];

            size++;
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }

    delete [] arr;
}

template <typename T>
bool isFinded(T value, T pos, T arr[], T arrSize) {
    for (size_t i = pos; i != arrSize; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
}

template <typename T >
void realloc(T * &arr, size_t size, size_t newSize) {
    T *new_arr = new T [newSize];
    size = newSize;
 
    for (size_t i = 0; i < size; ++i)
        new_arr[i] = arr[i];
 
    delete [] arr;
 
    arr = new_arr;
}
