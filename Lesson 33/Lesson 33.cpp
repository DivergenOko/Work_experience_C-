// Lesson 33. Вывод матрицы по столбцам/строкам.

#include <iostream> 
using namespace std;

int main()
{
    const int n = 3, m = 4; // n - строки, m - столбцы
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 11;
        }
    }

    // Вывод массива
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout.width(3);
            cout << matrix[i][j] << "\t";
        }
    }
    cout << endl<< "------------------str------------------" << "\n";

    // Вывод по строке/столбцу
    // для того чтобы сделать вывод двухмерного массива через двумерную индексацию
    // создадим массив УКАЗАТЕЛЕЙ для строк массива (n)
    int* str_mas[n];
    for (int i = 0; i < n; i++) { //строки
            str_mas[i] = matrix[i];
            cout.width(3);
            cout << "str_mas[i] = " << str_mas[i];
            cout << "\n";
        for (int j = 0; j < m; j++) { //столбцы
            cout.width(3);
            cout << "[" << str_mas[i][j] << "]" << "\t"; // двумерная индексация
        }
        cout << "\n";
    }

    cout << endl << "------------------stolb------------------" << "\n";

    int* stolb_mas[m];
    for (int j = 0; j < m; j++) {
        cout << "stolb_mas[i] = " << stolb_mas[j] << "\n";
        for (int i = 0; i < n; i++) {
            stolb_mas[i] = matrix[i];
            cout.width(3);
            cout << "[" << stolb_mas[i][j] << "]" << "\t" << "\n";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}