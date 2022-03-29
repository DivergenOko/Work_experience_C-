// Lesson 30. Лексикографическая сортировка по алфавиту строки из слов 
 
#include <iostream> 
using namespace std;

int main()
{
    const int ml = 256;
    char str[ml + 1];
    cin.getline(str, ml);
    int str_l = strlen(str);
    int word = 0;
    for (int i = 0; i < str_l; i++) {
        if (str[i] != 32 && (i == 0 || str[i - 1] == 32)) {
            word++;
        }
    }
    char** words = 0;
    int word_i, word_l, num = 0;
    if (word != 0) {
        words = new char* [word];
        char* word = str;
        for (int i = 0; i < str_l; i++) {
            if (str[i] != 32 && (i == 0 || str[i - 1] == 32)) {
                word = str + i;
                word_i = i;
            }
            if (str[i] != 32 && (i == str_l - 1 || str[i + 1] == 32)) {
                word_l = i - word_i + 1;
                words[num] = new char[word_l + 1];
                strncpy_s(words[num], word_l + 1, word, word_l);
                num++;
            }
        }
    }
    char* buff;
    int min_i;

    for (int i = 0; i < word - 1; i++) {
        min_i = i;
        for (int j = i + 1; j < word; j++) {
            if ((strcmp(words[j], words[min_i])) < 0) {
                min_i = j;
            }
            if (min_i != 0) {
                buff = words[i];
                words[i] = words[min_i];
                words[min_i] = buff;
            }
        }
    }

    for (int i = 0; i < word; i++) {
        cout << words[i] << "\n";
    }

    for (int i = 0; i < word; i++) {
        delete[] words[i];
        delete[] words;
    }
    return 0;
}