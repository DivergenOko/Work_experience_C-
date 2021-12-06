// Lesson 9.

#include <iostream>
#include <vector>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	double x1, x2, h, a, b, c;
	int n;
	cin >> x1 >> x2 >> n >> a >> b >> c;
	vector<double> x(n + 1);
	vector<double> y(n + 1);
	x[0] = x1;
	x[n] = x2;
	h = (x2 - x1) / n;

	for (int i = 1; i < n; i++) {
		x[i] = x[i - 1] + h;
	}

	for (int i = 0; i < n; i++) {
		y[i] = a * x[i] * x[i] + b * x[i] + c;
		//setprecision(3); // будет выводить в дробное число с закрпленной запятой (после запатой фиксированное количество знаков) УТОЧНИТЬ
	}

	fstream Output = fstream("Output.txt", ios::out);
	if () {
		for (int i = 0; i <= n; i ++) {
			Output << x[i] << " " << y[i];
		}
	}
}

