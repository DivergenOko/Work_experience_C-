// Lesson 50.

#include <iostream>
using namespace std;

int input_data(int* arr) {
    int n;
    cin >> n;
    if (n > 0) {
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    else {
        n = 0;
    }
    return n;
}

int main() {
    int max, min, n;
    int* arr = 0;
    n = input_data(arr);
}