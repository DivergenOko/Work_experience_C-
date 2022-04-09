// Lesson 53.

#include <iostream> 
#include <fstream> 
using namespace std;

int** input(int& n, int& m, char* filename) {
    n = 0, m = 0;
    int** arr = 0;
    fstream fin = fstream(filename, ios::in);
    if (fin.good()) {
        fin >> n >> m;
        if (n > 0 && m > 0) {
            arr = new int* [n];
            for (int i = 0; i < n; i++) {
                arr[i] = new int[m];
                for (int j = 0; j < m; j++) {
                    fin >> arr[i][j];
                }
            }
        }
    }
    return arr;
}

void transpose(int** arr, int** arrt, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arrt[j][i] = arr[i][j];
        }
    }
}

void output1(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
    }
}

void output2(int** arrt, int n, int m) {
    for (int i = 0; i < m; i++) {
        cout << '\n';
        for (int j = 0; j < n; j++) {
            cout << arrt[i][j] << '\t';
        }
    }
}

int main() {
    int n = 0, m = 0;
    char filename[] = "input.txt";
    int** arr = input(n, m, filename);

    int** arrt = new int* [m];
    for (int i = 0; i < m; i++) {
        arrt[i] = new int[n];
    }

    transpose(arr, arrt, n, m);
    output1(arrt, n, m);
    cout << endl << "--------------------------------------------";
    output2(arrt, n, m);

    if (arrt != 0) {
        for (int j = 0; j < n; j++) {
            delete[] arrt[j];
        }
        delete[] arrt;
    }

    if (arr != 0) {
        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
}