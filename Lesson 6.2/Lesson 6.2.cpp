// Lesson 6.2: Массивы.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		A[i] = (n - i) * 10;
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
