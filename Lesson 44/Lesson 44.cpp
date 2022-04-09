// Lesson 44. Передача двух параметров через ссылку

#include <iostream>
using namespace std;

void Square(double length, double Width, double& S, double& P) {
	S = length * Width;
	P = 2 * (length + Width);
}
void Output(double s) {
	cout << s << "\n";
}
int main() {
	double a, b, S, P;
	cin >> a >> b;

	Square(a, b, S, P);
	Output(S);
	Output(P);
}
