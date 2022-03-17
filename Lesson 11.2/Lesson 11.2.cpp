// Lesson 11.2 : заполнить массив с клавиатуры;  
// и высети те элементы которые делятся на 3;  
// выводить элементы которые делятся на 3 без остатка в отдельный массив.

#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
    int n, k = 0, j = 0;
    cin >> n;
    vector<int> x = vector<int>(n);
    vector<int> y = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        if (x[i] % 3 == 0) {
            y[k] = x[i];
            k++;
        }
    }
    y.resize(k);
    cout << k << endl << n;
    if (y.size() > 0) {
        for (j; j < k; j++) {
            cout << "y[" << y[j] << "]; ";
        }
    }
    else {
        cout << "y is emty!";
    }
}
