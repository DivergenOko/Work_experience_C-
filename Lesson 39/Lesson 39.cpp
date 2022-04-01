// Lesson 39. Задача: заполнить два одинаковых по размеру массива (не квадрат)
// из файла и сделать массив состоящий из чередующихся строк первого массива и второго 
// и массив состоящийиз чередующихся столбцов и вывести в два разных файла

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n = 0, m = 0; // n - строки, m - столбцы
    int** arr1 = 0;
    int** arr2 = 0;
    int** arr_str = 0; // массив из строк
    int** arr_slb = 0; // массив из столбцов
    fstream input = fstream("Input.txt", ios::in); // файл для ввода обоих массивов
    fstream output1 = fstream("Output1.txt", ios::out); // файл для вывода массива из строк
    fstream output2 = fstream("Output2.txt", ios::out); // файл для вывода массива из столбцов

    if (input.good()) { // проверка наличия файла и готовности к потоку данных
        input >> n >> m;
        // Инициализация массивов
        int** arr1 = new int* [n];
        for (int i = 0; i < n; i++) {
            arr1[i] = new int[m]; // для n-ой строки создаем m столбцов 
        }

        int** arr2 = new int* [n];
        for (int i = 0; i < m; i++) {
            arr2[i] = new int[m];
        }

        int** arr_str = new int* [n * 2];
        for (int i = 0; i < n * 2; i++) {
            arr_str[i] = new int[m];
        }

        int** arr_slb = new int* [n];
        for (int i = 0; i < n; i++) {
            arr_slb[i] = new int[m * 2];
        }

        // Заполнение массивов из файла
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                input >> arr1[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                input >> arr2[i][j];
            }
        }

        // Вывод на экран заполненных массивов (для отладки)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr1[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "------------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr2[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "------------------------------------------" << endl;

        // Массив с чередующимися строками
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr_str[i * 2][j] = arr1[i][j];
                arr_str[i * 2 + 1][j] = arr2[i][j];
            }
        }

        // Вывод массива с чередующимися строками
        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr_str[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "------------------------------------------" << endl;

        // Массив с чередующимися столбцами
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                arr_slb[i][j * 2] = arr1[i][j];
                arr_slb[i][j * 2 + 1] = arr2[i][j];
            }
        }

        // Вывод массива с чередующимися столбцами
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m * 2; i++) {
                cout << arr_slb[j][i] << "\t";
            }
            cout << "\n";
        }

        /////////////////////////////////////////////////////////////////////////////////
                // Открытие файла для записи массива из строк
        if (output1.good()) {
            for (int i = 0; i < n * 2; i++) {
                for (int j = 0; j < m; j++) {
                    output1 << arr_str[i][j] << "\t";
                }
                cout << "\n";
            }
            output1.close();
        }

        // Открытие файла для записи массива из столбцов
        if (output2.good()) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < m * 2; i++) {
                    output2 << arr_slb[j][i] << "\t";
                }
                cout << "\n";
            }
            output2.close();
        }
        input.close(); // закрытие файла
    }

    /* Очистка памяти
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            delete[] arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            delete[] arr2[i][j];
        }
    }
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m; j++) {
            delete[] arr_str[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m * 2; i++) {
            delete[] arr_slb[j][i];
        }
    }*/

    return 0;
}

