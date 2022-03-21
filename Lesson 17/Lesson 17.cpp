// Lesson 17: ввести с клавы значения массива и сложить их 

#include <iostream> 
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int* arr = new int[n](); // обявление массива 
    for (int i = 0; i < n; i++) {
        cin >> i;
        arr[i] = i;
        sum += arr[i]; // наращиваем сумму 
    }
    cout << "sum = " << sum;
    delete[] arr;
}