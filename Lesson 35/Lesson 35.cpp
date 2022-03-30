// Lesson 35. Сумма двух матриц

#include <iostream>
using namespace std;

int main()
{
	int Rows, Cols;
	cin >> Rows >> Cols;

	int** Mass1 = new int* [Rows];
	for (int i = 0; i < Rows; i++) {
		Mass1[i] = new int[Cols];
	}
		
	int** Mass2 = new int* [Rows];
	for (int i = 0; i < Rows; i++) {
		Mass2[i] = new int[Cols];
	}
		
	int** Mass3 = new int* [Rows];
	for (int i = 0; i < Rows; i++) {
		Mass3[i] = new int[Cols];
	}
		
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cin >> Mass1[i][j];
		}
	}

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cin >> Mass2[i][j];
		}
	}

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Mass3[i][j] = Mass1[i][j] + Mass2[i][j];
		}
	}

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << Mass3[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < Rows; i++) {
		delete[] Mass1[i];
	}
	delete[] Mass1;

	for (int i = 0; i < Rows; i++) {
		delete[] Mass2[i];
	}
	delete[] Mass2;

	for (int i = 0; i < Rows; i++) {
		delete[] Mass3[i];
	}
	delete[] Mass3;

	return 0;
}