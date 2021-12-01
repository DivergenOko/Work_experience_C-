// Lesson 6.1: Файловый ввод/вывод.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int m, s = 0, k;
	fstream Input = fstream("Output.txt", ios::in);

	cout << "Reading file";
	if (Input.good()) {
		Input >> m;
		cout << "m = " << m;
		for (int i = 1; i <= m; i++) {
			Input >> k;
			cout << "k = " << k;
			s += k;
		}
		Input.close();
	}
	cout << "Finish!\n";
}
