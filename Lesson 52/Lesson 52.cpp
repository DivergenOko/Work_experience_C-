// Lesson 52.

#include <iostream>
using namespace std;

int InputData(int*& Mass) {
    int n;
    cin >> n;

    if (n > 0) {
        Mass = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> Mass[i];
        }
    }
    else {
        n = 0;
    }
    return n;
}

int* InputData(int& n) {
    int* Mass = 0;
    cin >> n;

    if (n > 0) {
        Mass = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> Mass[i];
        }
    }
    else {
        n = 0;
    }
    return Mass;
}

int** InputData(int& n, int& m) {
    int** Mass = 0;
    cin >> n >> m;

    if (n > 0 && m > 0) {
        Mass = new int* [n];
        for (int i = 0; i < n; i++) {
            Mass[i] = new int[m];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> Mass[i][j];
            }
        }
    }
    else {
        n = 0;
        m = 0;
    }
    return Mass;
}

void InputData(int**& Mass, int& n, int& m) {
    cin >> n >> m;

    if (n > 0 && m > 0) {
        Mass = new int* [n];
        for (int i = 0; i < n; i++) {
            Mass[i] = new int[m];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> Mass[i][j];
            }
        }
    }
    else {
        Mass = 0;
        n = 0;
        m = 0;
    }
}

void MinMax(int* mas, int n, int& min, int& max) {
    min = mas[0];
    max = mas[0];
    for (int i = 0; i < n; i++) {
        if (mas[i] < min) {
            min = mas[i];
        }
        if (mas[i] > max) {
            max = mas[i];
        }
    }
}

void MinMax(int** mas, int n, int m, int& min, int& max) {
    min = mas[0][0];
    max = mas[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            {
                if (mas[i][j] < min) {
                    min = mas[i][j];
                }
                if (mas[i][j] > max) {
                    max = mas[i][j];
                }
            }
        }
    }
}

int main() {

    int Max, Min, n, m;
    int** Mass = 0;

    Mass = InputData(n, m);
    MinMax(Mass, n, m, Min, Max);
    cout << "Min = " << Min << "\n" << "Max = " << Max << "\n";
    if (Mass != 0) {
        for (int i = 0; i < n; i++) {
            delete[] Mass[i];
        }
        delete[] Mass;
    }
    cout << "\n";

    InputData(Mass, n, m);
    MinMax(Mass, n, m, Min, Max);
    cout << "Min = " << Min << "\n" << "Max = " << Max << "\n";
    if (Mass != 0) {
        for (int i = 0; i < n; i++) {
            delete[] Mass[i];
        }
        delete[] Mass;
    }
}