// Lesson 15

#include <iostream> 
using namespace std;
int main()
{
	int N, M = 0;
	cin >> N;
	int* Mass1 = new int[N];
	int* Mass2 = new int[N];
	for (int i = 0; i < N; i++)
		cin >> Mass1[i];

	for (int i = 0; i < N; i++)
		if (Mass1[i] % 3 == 0)
		{
			Mass2[M] = Mass1[i];
			M++;
		}
	if (M > 0)
	{
		Mass2 = (int*)realloc(Mass2, M * sizeof(Mass2[0]));
		for (int i = 0; i < M; i++)
			cout << Mass2[i] << " ";
	}
	else cout << "Massiv is empty!";

	delete[] Mass1;
	delete[] Mass2;
	return 0;
}