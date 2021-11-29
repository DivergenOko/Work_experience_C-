﻿// Lesson 5.3: C помощью кода создали файл.txt и записали туда текст.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int n, k, s = 0;
	cin >> n;

	// fstream - это стандартный файловый поток ввода/вывода (двунаправленный поток) для консоли. Output - имя потока.
	// () - открываем файловый поток связанный с файлом Output.txt, 
	// с помощью индификатора ios::out сообщаем, что файл будет использоваться для записи (ввода в файл);
	fstream Output = fstream("Output.txt", ios::out); 
	
	//Условие проверки создания и готовности файла. Если файл открыт переходим к выполнению действия.
	if (Output.good()) {
		// Записываем в файл числа которые ввели с клавиатуры.
		Output << n << "\n";
		for (int i = 1; i <= n; i++) {
			cin >> k;
			// Записываем выходной поток значений k.
			Output << k << " ";
		}
		// Чтобы сохранить данные в файле и закрыть его.
		Output.close();
	}
	// Конец работы с файлом.
	cout << "Finish!\n"; 
}


