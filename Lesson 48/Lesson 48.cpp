// Lesson 48.

#include <iostream>
using namespace std;

double func1(double a, double b) {
    a = 10;
    return a * b;
}

double func2(double* a, double b) {
    *a = 10;
    return *a * b;
}

double func3(double& a, double b) {
    a = 20;
    return a * b;
}

int main()
{
    double a, b;
    cin >> a >> b;

    double s = func1(a, b);
    cout << "s = " << s << "\n";
    cout << "a = " << a << "\n";

    double s = func2(&a, b);
    cout << "s = " << s << "\n";
    cout << "a = " << a << "\n";

    double s = func3(a, b);
    cout << "s = " << s << "\n";
    cout << "a = " << a << "\n";
}