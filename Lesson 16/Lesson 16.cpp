// Lesson 16

#include <iostream> 
using namespace std;

int main()
{
	int StaticMass[] = { 0x000000FF, 0x01000200, 0x00F0000F };
	int StaticMassSize = 3;

	for (int i = 0; i < StaticMassSize; i++)
		cout << StaticMass[i] << " ";
	cout << "\n";

	short* Mass = (short*)StaticMass;
	int MassSize = StaticMassSize * 2;

	for (int i = 0; i < MassSize; i++)
		cout << Mass[i] << " ";
	cout << "\n";

}