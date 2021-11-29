// Задача №8. Оператор вводит n - количество чисел с экрана, вводит n чисел. 
// Посчитать сумму и среднее арифметическое всех числе.

#include <iostream>
using namespace std;

int main()
{
    int num, N, i = 1, sum = 0;
    float sr;
    cout << "Number: ";
    cin >> num;

    for (i ;i <= num; i++) {
        cout << "N" << i << ": ";
        cin >> N;
        sum += N;
        cout << "sum = " << sum << endl;
    }
    sr = float(sum / num);
    cout << "sr = " << sr << endl;
}
