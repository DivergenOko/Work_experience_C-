// Lesson 51.

#include <iostream>
using namespace std;

void MinMax(const int* mas, int n, int& max, int& min) {
    min = mas[0];
    max = mas[0];
    for (int i = 0; i < n; i++) {
        if (mas[i] < min) min = mas[i];
        if (mas[i] > max) max = mas[i];
    }
}

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

int main() {
    int Max, Min, n;
    int* Mass = 0;

    n = InputData(Mass);
    MinMax(Mass, n, Max, Min);
    cout << "MAX =" << Max << "\n" << "MIN =" << Min << "\n";
    if (Mass != 0) {
        delete[] Mass;
    }

    Mass = InputData(n);
    MinMax(Mass, n, Max, Min);
    cout << "MAX=" << Max << "\n" << "MIN=" << Min << "\n";
    if (Mass != 0) {
        delete[] Mass;
    }
}