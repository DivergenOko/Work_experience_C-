// Lesson 21. 1) Сортировка по возростанию; 


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
    int buff, min_i;
    for (int i = 0; i < n; i++) {
        min_i = i;
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }
        if (i != min_i) {
            buff = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = buff;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "arr[i] = " << arr[i] << endl;
    }
    delete[] arr;
}