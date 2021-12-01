// Lesson 6. Задача №9 : Разложить число на простые множества.(Д.з)

#include <iostream>
using namespace std;

int main()
{
    int N, ost, del = 2;
    cout << "N: ";
    cin >> N;

    while (N >= del) {
        ost = N % del;
        if (ost == 0) {
            N = N / del;
            cout << del << " ";
        }
        else {
            del++;
        }
    }
}

