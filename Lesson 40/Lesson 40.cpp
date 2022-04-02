// Lesson 40.

#include <iostream> 
#include <sstream> 
using namespace std;

int main()
{
    const int MaxLength = 256;
    char Str[MaxLength + 1];
    cin.getline(Str, MaxLength);

    int StrLength = strlen(Str);
    int WordCount = 0;
    for (int i = 0; i < StrLength; i++)
        if (Str[i] != 32 && (i == 0 || Str[i - 1] == 32)) WordCount++;

    char** Words = 0;
    if (WordCount != 0)
    {
        Words = new char* [WordCount];
        char* Word = Str;
        int WordBeginIndex, WordLength, WordNumber = 0;
        for (int i = 0; i < StrLength; i++)
        {
            if (Str[i] != 32 && (i == 0 || Str[i - 1] == 32))
            {
                Word = Str + i;
                WordBeginIndex = i;
            }
            if (Str[i] != 32 && (i == StrLength - 1 || Str[i + 1] == 32))
            {
                WordLength = i - WordBeginIndex + 1;
                Words[WordNumber] = new char[WordLength + 1];
                //for (int j = 0; j < WordLength; j++) 
                // Words[WordNumber][j] = Str[WordBeginIndex + j]; 
                strncpy_s(Words[WordNumber], WordLength + 1, Word, WordLength);
                //Words[WordNumber][WordLength] = 0; 
                WordNumber++;
            }
        }
        char* Buff;
        int MinIndex;
        for (int i = 0; i < WordCount - 1; i++)
        {
            MinIndex = i;
            for (int j = i + 1; j < WordCount; j++)
                if (strcmp(Words[j], Words[MinIndex]) < 0) MinIndex = j;

            if (MinIndex != i)
            {
                Buff = Words[i];
                Words[i] = Words[MinIndex];
                Words[MinIndex] = Buff;
            }
        }

        for (int i = 0; i < WordCount; i++) cout << Words[i] << "\n";

        int result_l = 0;
        for (int i = 0; i < WordCount; i++) {
            result_l += strlen(Words[i]);
        }
        result_l += WordCount - 1;
        char* result = new char[result_l + 1];
        int Current_i = 0;
        /* Способ 1 пройтись по всем словам массива слов и пройтись по каждому слову

        for (int i = 0; i < WordCount; i++) {
         WordLength = strlen(Words[i]);
         for (int j = 0; j < WordLength; j++) {
          result[Current_i++] = Words[i][j];
         }
         if (i < WordCount - 1) {
          result[Current_i++] = ' ';
         }
         else {
          result[Current_i] = 0;
         }
        }*/

        /* Способ 2
        result[0] = 0;
        for (int i = 0; i < WordCount; i++) {
         strcat_s(result, result_l + 1, Words[i]);
         if(i < WordCount - 1) {
          strcat_s(result, result_l + 1, " ");
         }
        }*/

        // Способ 3 
        stringstream result_stream = stringstream(ios::out);
        for (int i = 0; i < WordCount; i++) {
            result_stream << Words[i];
            if (i < WordCount - 1) {
                result_stream << " ";
            }
        }
        strcpy_s(result, result_l + 1, result_stream.str().c_str());
        cout << result_stream.str().c_str() << "\n";

        for (int i = 0; i < WordCount; i++)
            delete[] Words[i];
        delete[] Words;
        delete[] result;
    }
    return 0;
}