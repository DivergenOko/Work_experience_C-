// Lesson 14
#include <iostream> 
using namespace std;

int main()
{
    int X = 10;
    int* M = &X;
    *M = 29;
    double Y = 9.81;
    double* N = &Y;
    cout << "X = " << X << "/n"
        << "M = " << M << "/n"
        << "Y = " << Y << "/n"
        << "N = " << N << "/n";

    long long int Z = 0xFF11F11FF00F1FF1;
    // 255 17 241 31 240 15 16 1 
    cout << "Z = " << Z << "/n";
    long long int* ZZ = &Z;
    unsigned char* K = (unsigned char*)ZZ;

    // a =(int)b; 
    // a = int(b); 
    // a = (int)(b); 

    for (int i = 0; i < 8; i++)
        cout << int(K[i]) << " ";

    for (int i = 0; i < 8; i++)
        cout << int(K + i) << " ";
}