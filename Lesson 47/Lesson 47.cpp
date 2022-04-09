// lesoon 47. Рассчитать значение  

#include <iostream>  
using namespace std;

void Output(double result) {
	cout << "y = " << result << "\n";
}

int main() {
	double a, b, c, x, y = 0;
	cin >> a >> b >> c >> x;
	y = result(x, a, b, c, y);
	Output(y);
	Output(result(a, b, c, x, y));
}

double result(double a, double b, double c, double x, double y) {
	y = a * x * x + b * x + c;
	return (y);
}