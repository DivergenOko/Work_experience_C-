// Lesson 18:  
// №1 Ввести с клавы значения массива и сложить их 
// №2 Разделить массив на два массива ченые числа и нечетные 

#include <iostream> 
using namespace std;

int main()
{
    int n, k = 0, m = 0;
    int sum = 0;
    cin >> n;
    int* arr = new int[n]; // обявление массива 
    int* arr_1 = new int[n]; // нечетные 
    int* arr_2 = new int[n]; // четные 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            arr_2[m] = arr[i];
            m++;
        }
        else {
            arr_1[k] = arr[i];
            k++;
        }
        if (k > 0) {
            arr_1 = (int*)realloc(arr_1, k * sizeof(arr_1[0])); // изменяем размер 
        }
        if (m > 0) {
            arr_2 = (int*)realloc(arr_2, m * sizeof(arr_2[0]));
        }
        //sum += arr[i]; // наращиваем сумму 
    }
    //cout << "sum = " << sum; 
    for (int i = 0; i < k; i++) {
        cout << "arr_1 = " << arr_1[i] << endl;
    }
    cout << "------------------" << endl;
    for (int i = 0; i < m; i++) {
        cout << "arr_2 = " << arr_2[i] << endl;
    }
    delete[] arr; // очищаем массив 
    delete[] arr_1;
    delete[] arr_2;
}