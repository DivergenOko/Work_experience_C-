// Lesson 12

#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
    int x = 10;
    int* M = &x;
    *M = 20; // х будет равен 20
    long long int z = 0xFF11F11F001FF1;

    unsigned char* K = (unsigned char*)&z; //преобразуем в другой тип данных
    for (int i = 0; i < 8; i++) {
        cout << int(K[i]) << " ";
    }
}
