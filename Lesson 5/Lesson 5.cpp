/*Задача №7.Дано два натуральных числа - n и m. Нужно посчитать сумму всех чисел,
которые находятся в диапозоне от n до m 
и делятся на k без остатка.*/

#include <iostream>
using namespace std;

int main()
{
    int n, m, k, i, s = 0, ost;
    cin >> n >> m >> k;
    i = n;

    while (i <= m) {
        //ost = i % k;
        //if (ost == 0) {
        //    s += i;
        //}
        if (i % k == 0) {
            s += i;
        }
        i++;
    }
    cout << "s = " << s << "\n";
}
