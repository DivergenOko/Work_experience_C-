// Lesson 26. Определение количества слов в строке 
 
#include <iostream> 
using namespace std;

int main()
{
    const int MaxL = 256;
    char str[MaxL + 1];
    cin.getline(str, MaxL);

    int strL = strlen(str);
    int word = 0;
    for (int i = 0; i < strL; i++) {
        if (str[i] != 32 && (i == 0 || str[i - 1] == 32)) {
            word++;
        }
    }
    cout << "word = " << word;
}