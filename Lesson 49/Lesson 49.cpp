// Lesson 49. 

#include <iostream> 
using namespace std;

void poly(double x, int n) {
    double y;
    double* Coaf = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> Coaf[n - i];
    }
    y = 0;
    double pow = 1;
    for (int i = 0; i <= n; i++) {
        y += pow * Coaf[i];
        pow *= x;
    }
    cout << y;
}
int main() {
    double x, y;
    int n;
    cin >> x >> n;
    poly(x, n);
}