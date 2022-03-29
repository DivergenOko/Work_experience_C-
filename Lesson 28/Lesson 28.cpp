// Lesson 28. Поис подстроки 
 
#include <iostream> 
using namespace std;

int main()
{
    int num;
    int k = 0;
    const int str_ml = 256;
    const int str_f_ml = 256;
    char str[str_ml + 1];
    char str_f[str_f_ml + 1];

    cin.getline(str, str_ml);
    int str_l = strlen(str);

    cin.getline(str_f, str_l);
    int str_f_l = strlen(str_f);
    // qwerty qwewe qwqweder 
    // qwe 

    num = str_l - str_f_l + 1;
    bool find;
    for (int i = 0; i < num; i++) {
        find = true;
        for (int j = 0; j < str_f_l; j++) {
            if (str_f[j] != str[i + j]) {
                find = false;
                break;
            }

        }

        if (find) {
            k++;
        }
    }
    cout << "Количество повторений: " << k;
}