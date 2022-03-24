// Lesson 20: минимальный элемент поменять с максимальным элементом местами.  

#include <iostream>   
using namespace std;

int main()
{
    int n, min_i = 0, max_i = 0, buff = 0;
    cin >> n;
    int* arr = new int[n]; // обявление массива   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "arr[i] = " << arr[i] << endl;
    }

    // Минимальный элемент массива 
    for (int i = 1; i < n; i++) {
        if (arr[min_i] > arr[i]) {
            min_i = i;
        }
    }
    buff = arr[min_i];

    // Максимальный элемент массива 
    for (int i = 1; i < n; i++) {
        if (arr[max_i] < arr[i]) {
            max_i = i;
        }
    }
    cout << "---------------------------------" << endl;

    // Меняем элементы местами 
    arr[min_i] = arr[max_i];
    arr[max_i] = buff;

    for (int i = 0; i < n; i++) {
        cout << "arr[i] = " << arr[i] << endl;
    }
    delete[] arr;
}