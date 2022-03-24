// Lesson 22. 2) Сортировка по убыванию; 

#include <iostream> 
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "arr[i] = ";
        cin >> arr[i];
    }
    cout << "--------------------------" << endl;

    int buff, max_i;
    for (int i = 0; i < n; i++) {
        max_i = i;
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[max_i]) {
                max_i = j;
            }
        }
        if (i != max_i) {
            buff = arr[i];
            arr[i] = arr[max_i];
            arr[max_i] = buff;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "arr[i] = " << arr[i] << endl;
    }
    delete[] arr;
}