// Lesson 41. столбцы и строки

#include <iostream> 
#include <fstream> 
using namespace std;
int main()
{
    int rows;
    int cols;
    int** arr1 = 0;
    int** arr2 = 0;

    fstream input = fstream("Input.txt", ios::in);
    if (input.good()) {
        input >> rows >> cols;
        arr1 = new int* [rows];
        arr2 = new int* [rows];
        for (int i = 0; i < rows; i++) {
            arr1[i] = new int[cols];
            arr2[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                input >> arr1[i][j];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                input >> arr2[i][j];
            }
        }
        input.close();
    }
    else {
        cout << "not found file";
    }

    if (arr1 != 0 && arr2 != 0) {
        int irows = rows, icols = cols * 2;
        int** arr = new int* [irows];
        for (int i = 0; i < irows; i++) {
            arr[i] = new int[icols];
        }
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                arr[j][i * 2] = arr1[j][i];
                arr[j][i * 2 + 1] = arr2[j][i];
            }
        }
        for (int i = 0; i < irows; i++) {
            for (int j = 0; j < icols; j++) {
                cout << arr[i][j];
                if (i < icols - 1) {
                    cout << " ";
                }
            }
            if (i < irows - 1) {
                cout << "\n";
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr1[i];
        delete[] arr2[i];
    }
    delete[] arr1;
    delete[] arr2;
}