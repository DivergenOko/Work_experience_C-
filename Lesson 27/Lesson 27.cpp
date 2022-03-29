// Lesson 27. Разбиение на слова решение №2 (без вложенного цикла) 
 
#include <iostream> 
using namespace std;

int main()
{
    const int MaxL = 256;
    char Str[MaxL + 1]; // Str - ссылка на область памяти 
    cin.getline(Str, MaxL);
    //char s[] = " "; 
    //char* word = s; 
    char* word = Str;
    char buff = 0;

    int StrL = strlen(Str);
    // Отладка: asdf qwerty ertnm 4 р 1234 
    int StartIndex;
    for (int i = 0; i < StrL; i++) {
        if (Str[i] != 32 && (i == 0 || Str[i - 1] == 32)) {
            StartIndex = i;
            word = Str + i; // & (*(Str + i)) адрес начала слова 
        }
        if (Str[i] != 32 && (i == StrL - 1 || Str[i + 1] == 32)) {
            if (i != StrL - 1) {
                buff = Str[i + 1];
                Str[i + 1] = 0;
            }
            cout << word << "\n";
            if (i != StrL - 1) {
                Str[i + 1] = buff;
            }
        }
    }
    return 0;
}