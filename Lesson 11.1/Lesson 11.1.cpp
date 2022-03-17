// Lesson 11.1: Статический массив.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int MaxSize = 100;
	int Mass1[MaxSize];
	int Mass2[MaxSize];

	// int Mass3[] = {2, 5, 7, 1, 0};

	int N, M = 0;
	cin >> N;
	if (N < 0 || N > MaxSize)
		cout << "Size not correct!";
	else
	{
		for (int i = 0; i < N; i++)
			cin >> Mass1[i];

		for (int i = 0; i < N; i++)
			if (Mass1[i] % 3 == 0)
			{
				Mass2[M] = Mass1[i];
				M++;
			}

		if (M > 0)
			for (int i = 0; i < M; i++)
				cout << Mass2[i] << " ";
		else cout << "Massiv is empty!" << "\n";
	}
	return 0;
}