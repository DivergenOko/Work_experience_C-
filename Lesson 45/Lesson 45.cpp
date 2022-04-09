// Lesson 45. на вход массив , на выходе макс и мин через функцию

#include <iostream>
using namespace std;

void MinMax(const int* mas, int n, int& max, int& min) {
	min = mas[0];
	max = mas[0];
	for (int i = 0; i < n; i++) {
		if (mas[i] < min) min = mas[i];
		if (mas[i] > max) max = mas[i];
	}
}
int main()
{
	int max, min, n;
	cin >> n;
	int* mas = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}

	MinMax(mas, n, max, min);
	cout << "MAX =" << max << ";" << "MIN =" << min;
	delete[] mas;
}