// Lesson 46. на вход массив , на выходе макс и мин через функцию.

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
int InputData(int*& Mass) {
	int n;
	cin >> n;
	if (n > 0) {
		Mass = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> Mass[i];
		}
	}
	else {
		return 0;
	}
	return n;
}
int main() {
	int max, min, n;
	int* Mass = 0;
	n = InputData(Mass);

	MinMax(Mass, n, max, min);
	cout << "MAX=" << max << ";" << "MIN=" << min;
	if (n != 0) {
		delete[] Mass;
	}
}