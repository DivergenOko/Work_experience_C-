// Lesson 34. Поменять местами столбцы и строки 
// Отладка: 
// n = 3, m = 5 
// Ввод: 
// 1 2 3 4 5  
// 6 7 8 9 10 
// 11 12 13 14 15 
// Вывод: 
// 1 6 11 
// 2 7 12 
// 3 8 13 
// 4 9 14 
// 5 10 15 

#include <iostream>  
using namespace std;

int main()
{
    int n, m; // n - строки, m - столбцы  
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    // Инициализация массивов 
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m]; // для нной строки создаем м столбцов 
    }

    int** matrix_copy = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix_copy[i] = new int[n];
    }

    // Заполнение первоначального массива 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 11;
        }
    }

    // Вывод на экран 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "___________________________" << endl;

    // Копируем элементы первого массива во второй 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_copy[j][i] = matrix[i][j];
        }
    }

    // у второго массива теперь количество столбцов равно количеству строк 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix_copy[i][j] << "\t";
        }
        cout << "\n";
    }

    // Очистка памяти 
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n; i++) {
        delete[] matrix_copy[i];
    }
    delete[] matrix_copy;
}