#include <iostream>
using namespace std;


template <typename T>
bool isFinded(T value, T arr[], T arrSize);

template <typename T>
void realloc(T * &arr, size_t size, size_t newSize);


int main() {
    setlocale(LC_ALL, "Russian");

    int n = 5;
    int m = 4;
    int size = 0;

    int arr1[n] = {1, 2, 4, 4, 5};
    int arr2[m] = {1, 2, 4, 7};
    int *arr = new int[size];

    for (int i = 0; i < n; ++i) {
        if (isFinded(arr1[i], arr2, m) && !isFinded(arr1[i], arr, size)) {
            realloc(arr, size, size + 1);
            arr[size] = arr1[i];

            size++;
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }

}

template <typename T>
bool isFinded(T value, T arr[], T arrSize) {
    bool flag = false;

    for (size_t i = 0; i != arrSize; ++i) {
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
 
    for (size_t i = 0; i < size; ++i)
        new_arr[i] = arr[i];
 
    delete [] arr;
 
    arr = new_arr;
}

