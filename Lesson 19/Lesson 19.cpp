// Lesson 19.
// Дано: два массива заполненнных с клавиатуры (не повторяющимися числами).
// Необходимо: сделать из двух массивов один так чтобы элементы в нем не сопадали.
// Пример: ввод  [1 2 3 4] 
//               [5 4 7 8]
//         вывод [1 2 3 5 7 8]

#include <iostream> 
using namespace std;

int main()
{
    int n, k, m = 0, size;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;

    int* arr = new int[n + k]; 
    int* arr_1 = new int[n];
    int* arr_2 = new int[k];
    size = n + k;

    ///////////////////<input\output>//////////////////////
    
    // Ввод первого массива
    for (int i = 0; i < n; i++) {
        cin >> arr_1[i];
    }
    // Вывод первого массива
    for (int i = 0; i < n; i++) {
        cout << "arr_1[i] = " << arr_1[i] << endl;
    }
    cout << "------------------" << endl;
    
    // Ввод второго массива
    for (int i = 0; i < k; i++) {
        cin >> arr_2[i];
    }
    // Вывод второго массива
    for (int i = 0; i < k; i++) {
        cout << "arr_2[i] = " << arr_2[i] << endl;
    }
    
    //////////////////////////////////////////////////////

    for (int i = 0; i < size; i++) {
        if (arr_1[i] != arr_2[i]) {
            arr[size] = arr_1[i];
            //cout << arr[size] << endl;
            m++;
        }
        else {
            arr[size] = 0;
        }
    }
    cout << "arr[size] = " << arr[size];

    for (int i = 0; i < size; i++) {
        if (arr_2[i] != arr_1[i]) {
            m ++;
            arr[m] = arr_2[i];
        }
        if (m > 0) {
            arr_2 = (int*)realloc(arr_2, m * sizeof(arr_2[0]));
        }
    }

    cout << "------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr = " << arr[i] << endl;
    }
    delete[] arr; // очищаем массив 
    delete[] arr_1;
    delete[] arr_2;
}
