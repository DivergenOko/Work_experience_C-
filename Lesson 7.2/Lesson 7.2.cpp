// Lesson 7.2: Заполнение массива случайными ВЕЩЕСТВЕННЫМИ числами и вывод на экран.

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	float min, max;
	int n;
	cout << "Input n in massiv: ";
	cin >> n;
	cout << endl << "Input diapason min: ";
	cin >> min;
	cout << endl << "Input diapason max: ";
	cin >> max;
	vector<float> A(n);

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() * (max - min) / RAND_MAX + min;
		cout << i << "--> ";
		cout << "[" << A[i] << "]" << " " << endl;
	}

}