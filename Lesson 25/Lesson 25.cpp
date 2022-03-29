// Lesson 25 --> Таблица ASCI 

#include <iostream> 
using namespace std;

int main() {
    const int str = 10;
    char Str[str + 1];
    Str[str] = 0;

    for (int i = 0; i < str; i++) {
        Str[i] = 48 + i;
    }
    cout << Str << '\n';
    char str2[] = "This is str !";
    cout << str2 << "\n";

    char str3[] = { 'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 's', 't', 'r', ' ', '!', '\0' };
    cout << str3 << "\n";

    char str4[] = "--> This\tis\n\\str\\\n";
    cout << str4 << "\n";

    char str5[] = { 65, 66, 32, 10, 13, 50, 7, 0 }; // 10, 13 = \n для Винды; для Линукса 10, 7 - пищалка 
    cout << str5 << "\n";

    const int s = 100;
    char str6[s + 1];
    /*cin >> str6; // син вводит строку до пробела и энтера любого разделителя
    //  преобразование в инт в номер символа
    int n = strlen(str6); // возвращает длину строки
    for (int i = 0; i < n; i++) {
     cout << int(str6[i]) << " " << endl;
     cout << str6[i] << " " << endl;
    }
    cout << str6 << "\n";

    cout << "A" << 'A';*/
    // "A" - это чар строка всего содержаит А и 0 
    // 'A' - 1 байт массив 

    // считывание потока данных строки 
    int m = 0;
    cin.getline(str6, s);
    cout << str6 << "\n";
    int n = strlen(str6);
    for (int i = 0; i < n; i++) {
        if (int(str6[0] != 32)) {
            if (int(str6[i]) == 32 and int(str6[i + 1] != 32) or int(str6[i]) != 32 and int(str6[i + 1] == 0)) {
                m++;
                cout << "word_kol = " << m << endl;
            }
        }
        else if (int(str6[0] == 32)) {
            if (int(str6[i]) == 32 and int(str6[i + 1] != 32) or int(str6[i]) != 32 and int(str6[i + 1] == 0)) {
                m++;
                cout << "word_kol = " << m - 1 << endl;
            }
        }
    }
}