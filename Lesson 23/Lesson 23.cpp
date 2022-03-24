// Lesson 23. 3) Сортировка по модулю. 

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

    int buff, min_i;
    int babs, cabs;
    for (int i = 0; i < n; i++) {
        min_i = i;
        if (arr[i] < 0) {
            babs = -arr[min_i];
        }
        else {
            babs = arr[min_i];
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < 0) {
                cabs = -arr[j];
            }
            else {
                cabs = arr[j];
            }
            if (cabs < babs) {
                min_i = j;
                if (arr[min_i] < 0) {
                    babs = -arr[min_i];
                }
                else {
                    babs = arr[min_i];
                }
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